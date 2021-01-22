from torch import nn
import torch
from torch.nn.utils.rnn import pad_packed_sequence, pack_padded_sequence, pad_sequence, pack_sequence, PackedSequence

# bcbca


_input = torch.Tensor([1,2,1,2,0])

torch.manual_seed(42)
# # torch.random = 42

# # embeddings = nn.Embedding(4,4)

# _linear = nn.Linear(5, 1)
# r = _linear(_input)


# res = embeddings(_input)
pass
pass



class TestModel(nn.Module):

    def __init__(self):
        super(TestModel, self).__init__()

        self.line1 = nn.Linear(5,1, bias=True)

        self.line2 = nn.Linear(1,9)

    def forward(self, _input):
        r1 = self.line1(_input)
        r2 = self.line2(r1)
        return r2

model = TestModel()
r = model(_input)


a = 1




# embeddings = nn.Embedding(10, 3)
# input = [[1,2,3,4], [5,6,7, 0], [9, 2, 0, 0]]
# input = torch.LongTensor(input)

# lengths = torch.LongTensor([4, 3, 2])
# # embed = embeddings(input)

# packed_input = pack_padded_sequence(input, lengths, batch_first=True)

# embed = embeddings(packed_input.data)

# a = torch.tensor([1,2,3])
# b = torch.tensor([4,5])
# c = torch.tensor([6])
# res = pack_sequence([a, b, c])
# test = PackedSequence(data=torch.tensor([ 1,  4,  6,  2,  5,  3]), batch_sizes=torch.tensor([ 3,  2,  1]))
pass