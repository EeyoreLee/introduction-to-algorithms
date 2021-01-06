# -*- encoding: utf-8 -*-
'''
@create_time: 2020/12/28 10:48:53
@author: lichunyu
'''


import torch
import torch.nn as nn
import torch.nn.functional as F

droput = nn.Dropout(0.1)

x = torch.randn(5, 2)

m = nn.Linear(2, 3)

output = m(x)

pass