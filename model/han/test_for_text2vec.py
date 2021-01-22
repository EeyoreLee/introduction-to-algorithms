# -*- encoding: utf-8 -*-
'''
@create_time: 2021/01/22 17:37:59
@author: lichunyu
'''
from text2vec import Similarity

a = '如何更换花呗绑定银行卡'
b = '花呗更改绑定银行卡'

sim = Similarity()
s = sim.get_score(a, b)
print(s)