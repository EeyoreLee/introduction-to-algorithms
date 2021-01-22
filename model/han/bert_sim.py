# -*- encoding: utf-8 -*-
'''
@create_time: 2021/01/22 15:32:21
@author: lichunyu
'''


from transformers import BertModel, BertTokenizer
import torch
import numpy as np


# test = ['油气管道', '酯类', '工业锅炉','导热油炉','锅炉配套产品','锅炉管','水处理设备','节能环保设备','丁内酯','园林机械','港口机械',\
#     '贸易公司与经销商','国内贸易','进出口贸易','出口贸易','进口贸易','工业产品经销商','工业机械产品经销商','轴承经销商','乙酸甲酯',\
#         '冶金产品经销商','加工贸易','电气产品经销商','供应链贸易','原材料贸易','化工产品贸易','尿素贸易']

with open('/Users/lichunyu/data/wanli_classify/sim.txt', 'r', encoding='utf8') as f:
    test = f.read().splitlines()

res = []

model = BertModel.from_pretrained('bert-base-chinese')
tokenizer = BertTokenizer.from_pretrained('bert-base-chinese')
origin = '电器检测'
# a_in = tokenizer(origin, return_tensors='pt', max_length=10, padding='max_length')
a_in = tokenizer(origin, return_tensors='pt')
a_out = model(input_ids=a_in['input_ids'], attention_mask=a_in['attention_mask'])
a_pooler_output = a_out['pooler_output'][0].detach().numpy()
for i in test:
    # b_in = tokenizer(i, return_tensors='pt', max_length=10, padding='max_length')
    b_in = tokenizer(i, return_tensors='pt')
    b_out = model(input_ids=b_in['input_ids'], attention_mask=b_in['attention_mask'])
    b_pooler_output = b_out['pooler_output'][0].detach().numpy()

    sim = np.dot(a_pooler_output[:,None].T, b_pooler_output[:, None])[0][0]/(np.linalg.norm(a_pooler_output) * np.linalg.norm(b_pooler_output))
    print('{} <>  {} : {}'.format(origin, i, sim))
    res.append([i, sim])

sim_res = list(sorted(res, key=lambda x: x[-1], reverse=True))[:20]
    # print(sim)
pass