# -*- encoding: utf-8 -*-
'''
@create_time: 2021/01/05 14:15:07
@author: lichunyu
'''
import time


from torch import nn
import torch
from torch.nn.modules.activation import Tanh
from torch.nn.modules.loss import CrossEntropyLoss
from torch.nn.utils.rnn import PackedSequence, pack_padded_sequence, pad_packed_sequence, pack_sequence
import torch.nn.functional as F
from torch.optim import AdamW, Adam
from transformers import BertModel, BertTokenizer, BertForSequenceClassification, BertPreTrainedModel
# from transformers.models.bert.modeling_bert import BertEmbeddings



class BertEmbeddings(BertModel):
    pass


class WordAttention(nn.Module):

    def __init__(self, vocab_size, embed_dim, gru_hidden_dim, gru_num_layers, dropout, attention_dim):
        super(WordAttention, self).__init__()

        # self.embeddings = nn.Embedding(vocab_size, embed_dim)
        self.bert = BertEmbeddings.from_pretrained('bert-base-uncased')

        self.gru = nn.GRU(embed_dim, gru_hidden_dim, num_layers=gru_num_layers, batch_first=True, bidirectional=True, dropout=dropout)

        self.layer_norm = nn.LayerNorm(2*gru_hidden_dim, elementwise_affine=True)

        self.dropout = nn.Dropout(dropout)

        self.attention = nn.Linear(2*gru_hidden_dim, attention_dim)

        self.block_vector = nn.Linear(attention_dim, 1, bias=False)

        self.tanh = Tanh()

        # self.clf = nn.Linear(2*gru_hidden_dim, 3)

    def forward(self, blocks, block_lengths, attention_mask):

        block_lengths, perm_idx = block_lengths.sort(dim=0, descending=True)
        blocks = blocks[perm_idx]

        blocks = self.embeddings(blocks)
        # blocks = self.bert(input_ids=blocks).last_hidden_state  # 做了pack paded 不需要attention_mask
        blocks = self.dropout(blocks)

        packed_words = pack_padded_sequence(blocks, block_lengths, batch_first=True)
        # packed_words = PackedSequence(blocks, block_lengths)

        valid_bsz = packed_words.batch_sizes

        packed_words, _ = self.gru(packed_words)

        norm_words = self.layer_norm(packed_words.data)

        att = self.tanh(self.attention(norm_words.data))
        att = self.block_vector(att).squeeze(1)

        val = att.max()
        att = torch.exp(att - val)

        att, _ = pad_packed_sequence(PackedSequence(att, valid_bsz), batch_first=True)

        att_weights = att / torch.sum(att, dim=1, keepdim=True)

        blocks, _ = pad_packed_sequence(packed_words, batch_first=True)

        blocks = blocks * att_weights.unsqueeze(2)
        blocks = blocks.sum(1)

        _, unperm_idx = perm_idx.sort(dim=0, descending=False)
        blocks = blocks[unperm_idx]

        att_weights = att_weights[unperm_idx]

        # logits = self.clf(blocks)

        # return logits, blocks, att_weights
        return blocks, att_weights


class BlockAttention(nn.Module):

    def __init__(self, vocab_size, embed_dim, word_gru_hidden_dim, word_gru_num_layers, dropout, attention_dim, block_gru_hidden_dim, block_gru_num_layers, \
                block_attention_dim):
        """[summary]

        :param vocab_size: [description]
        :type vocab_size: [type]
        :param embed_dim: [description]
        :type embed_dim: [type]
        :param word_gru_hidden_dim: [description]
        :type word_gru_hidden_dim: [type]
        :param word_gru_num_layers: [description]
        :type word_gru_num_layers: [type]
        :param dropout: [description]
        :type dropout: [type]
        :param attention_dim: [description]
        :type attention_dim: [type]
        :param block_gru_hidden_dim: [description]
        :type block_gru_hidden_dim: [type]
        :param block_gru_num_layers: [description]
        :type block_gru_num_layers: [type]
        """                
        super(BlockAttention, self).__init__()

        self.word_attention = WordAttention(vocab_size, embed_dim, word_gru_hidden_dim, word_gru_num_layers, dropout, attention_dim)

        self.gru = nn.GRU(2*word_gru_hidden_dim, block_gru_hidden_dim, block_gru_num_layers, dropout=dropout, bidirectional=True, batch_first=True)

        self.layer_norm = nn.LayerNorm(2*block_gru_hidden_dim, elementwise_affine=True)

        self.dropout = nn.Dropout(dropout)

        self.attention = nn.Linear(2*block_gru_hidden_dim, block_attention_dim)

        self.page2vector = nn.Linear(block_attention_dim, 1, bias=False)

        self.tanh = Tanh()


    def forward(self, docs, docs_lengths, blocks_lengths, attention_mask):
        docs_lengths, docs_perm_idx = docs_lengths.sort(dim=0, descending=True)
        docs = docs[docs_perm_idx]

        blocks_lengths = blocks_lengths[docs_perm_idx]

        packed_blocks = pack_padded_sequence(docs, lengths=docs_lengths.tolist(), batch_first=True)
        valid_bsz = packed_blocks.batch_sizes

        packed_blocks_lengths = pack_padded_sequence(blocks_lengths, lengths=docs_lengths, batch_first=True)

        blocks, word_att_weight = self.word_attention(packed_blocks.data, packed_blocks_lengths.data, attention_mask)

        blocks = self.dropout(blocks)

        packed_blocks, _ = self.gru(PackedSequence(blocks, valid_bsz))

        normed_blocks = self.layer_norm(packed_blocks.data)

        att = torch.tanh(self.attention(normed_blocks))
        att = self.page2vector(att).squeeze(1)

        val = att.max()
        att = torch.exp(att - val)

        att, _ = pad_packed_sequence(PackedSequence(att, valid_bsz), batch_first=True)

        blocks_att_weight = att / torch.sum(att, dim=1, keepdim=True)

        docs, _ = pad_packed_sequence(packed_blocks, batch_first=True)

        docs = docs * blocks_att_weight.unsqueeze(2)
        docs = docs.sum(dim=1)

        word_att_weight, _ = pad_packed_sequence(PackedSequence(word_att_weight, valid_bsz), batch_first=True)

        _, doc_unperm_idx = docs_perm_idx.sort(dim=0, descending=False)
        docs = docs[doc_unperm_idx]

        word_att_weight = word_att_weight[doc_unperm_idx]
        blocks_att_weight = blocks_att_weight[doc_unperm_idx]

        return docs, word_att_weight, blocks_att_weight


class WordBlockHierarchicalAttention(nn.Module):

    def __init__(self, vocab_size, embed_dim, word_gru_hidden_dim, word_gru_num_layers, dropout, attention_dim, block_gru_hidden_dim, block_gru_num_layers, \
                block_attention_dim, num_classes):
        super(WordBlockHierarchicalAttention, self).__init__()

        self.blocks_attention = BlockAttention(vocab_size, embed_dim, word_gru_hidden_dim, word_gru_num_layers, dropout, attention_dim, block_gru_hidden_dim, block_gru_num_layers, \
                block_attention_dim)

        self.clf = nn.Linear(2*block_gru_hidden_dim, num_classes)

    def forward(self, docs, docs_lengths, blocks_lengths, attention_mask):
        docs, word_att_weight, block_att_weight = self.blocks_attention(docs, docs_lengths, blocks_lengths, attention_mask)

        scores = self.clf(docs)
        scores = F.softmax(scores, dim=-1)

        return scores, word_att_weight, block_att_weight






if __name__ == '__main__':
    # model = WordAttention(vocab_size=30522, embed_dim=512, gru_hidden_dim=512, gru_num_layers=2, dropout=0.1, attention_dim=512)
    model = WordBlockHierarchicalAttention(vocab_size=30522, embed_dim=768, word_gru_hidden_dim=512, word_gru_num_layers=2, dropout=0.1, attention_dim=512, \
            block_gru_hidden_dim=512, block_gru_num_layers=2, block_attention_dim=512, num_classes=3)

    input = torch.LongTensor([[[1,2,0,0,0],[3,4,5,0,0],[0,0,0,0,0]],
                              [[3,4,5,0,0],[6,7,0,0,0],[0,0,0,0,0]],
                              [[31,0,0,0,0],[31,2,0,0,0],[3,4,0,0,0]],
                              [[2,3,4,5,6],[0,0,0,0,0],[0,0,0,0,0]],
                              [[2,3,2,0,0],[0,0,0,0,0],[0,0,0,0,0]]])

    lengths = torch.LongTensor([2,2,3,1,1])
    attention_mask = torch.LongTensor([[[1,1,0,0,0],[1,1,1,0,0],[0,0,0,0,0]],
                                        [[1,1,1,0,0],[1,1,0,0,0],[0,0,0,0,0]],
                                        [[1,0,0,0,0],[1,1,0,0,0],[1,1,0,0,0]],
                                        [[1,1,1,1,1],[0,0,0,0,0],[0,0,0,0,0]],
                                        [[1,1,1,0,0],[0,0,0,0,0],[0,0,0,0,0]]])

    words_lengths = torch.LongTensor([[2,3,0],
                                      [3,2,0],
                                      [1,2,2],
                                      [5,0,0],
                                      [4,0,0]])

    labels = torch.LongTensor([0,0,1,1,2])

    model.train()
    loss_fn = CrossEntropyLoss()
    batch_loss = 0
    optimizer = AdamW(model.parameters(), lr=5e-5, eps=1e-8)

    for i in range(25):
        batch_loss = 0
        model.zero_grad()
        logits, word_att_weight, block_att_weight = model(input, lengths, words_lengths, attention_mask)
        # logits, blocks, att_weights = model(input, lengths)
        print('**************************************')
        print('===========logits========={}'.format(logits))
        print('===========att_weights========={}'.format(block_att_weight))
        loss = loss_fn(logits, labels)
        print('===========loss=========={}'.format(loss))
        print('**************************************')
        batch_loss += loss.item()
        loss.backward()
        optimizer.step()
        time.sleep(4)
    pass