# -*- encoding: utf-8 -*-
'''
@create_time: 2021/01/22 17:11:08
@author: lichunyu
'''


from gensim.models import KeyedVectors
import time
import os

bt = time.time()
file = '/Users/lichunyu/data/Tencent_AILab_ChineseEmbedding/Tencent_AILab_ChineseEmbedding.txt'
filebin = '/Users/lichunyu/data/Tencent_AILab_ChineseEmbedding/Tencent_AILab_ChineseEmbedding.bin'
word_vec = KeyedVectors.load(filebin, mmap='r')
print('success cost: {}'.format(time.time()-bt))
pass