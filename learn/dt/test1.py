from torch import nn
import torch
from torch.nn.utils.rnn import pad_packed_sequence, pack_padded_sequence, pad_sequence, pack_sequence, PackedSequence


# embeddings = nn.Embedding(10, 3)
# input = [[1,2,3,4], [5,6,7, 0], [9, 2, 0, 0]]
# input = torch.LongTensor(input)

# lengths = torch.LongTensor([4, 3, 2])
# # embed = embeddings(input)

# packed_input = pack_padded_sequence(input, lengths, batch_first=True)

# embed = embeddings(packed_input.data)

a = torch.tensor([1,2,3])
b = torch.tensor([4,5])
c = torch.tensor([6])
res = pack_sequence([a, b, c])
test = PackedSequence(data=torch.tensor([ 1,  4,  6,  2,  5,  3]), batch_sizes=torch.tensor([ 3,  2,  1]))
pass