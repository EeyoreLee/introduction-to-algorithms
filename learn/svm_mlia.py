# -*- encoding: utf-8 -*-
'''
@create_time: 2020/06/22 17:26:06
@author: lichunyu
'''
import numpy as np
import matplotlib.pyplot as plt


def gaussian(x, l):
    gamma = 1.0
    return np.exp(-gamma *  (x-l) ** 2)


x = np.arange(-4, 5, 1)
y = np.array((x >= -2) & (x <= 2), dtype='int')


plt.scatter(x[y==0], [0]*len(x[y==0]))
plt.scatter(x[y==1], [0]*len(x[y==1]))
plt.show()