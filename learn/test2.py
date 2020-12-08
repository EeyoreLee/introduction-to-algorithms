import torch
import numpy as np
from torch.utils.data import TensorDataset, DataLoader
a = torch.tensor([[1, 2, 3], [4, 5, 6], [7, 8, 9], [1, 2, 3], [4, 5, 6], [7, 8, 9], [1, 2, 3], [4, 5, 6], [7, 8, 9], [1, 2, 3], [4, 5, 6], [7, 8, 9]])

b = torch.tensor([44, 55, 66, 44, 55, 66, 44, 55, 66, 44, 55, 66])

train_ids = TensorDataset(a, b) 


np.pv()

pass