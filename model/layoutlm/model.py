# -*- encoding: utf-8 -*-
'''
@create_time: 2021/02/01 14:30:32
@author: lichunyu
'''


import torch
from torch import nn
import torch.nn.functional as F

import numpy as np
from transformers import LayoutLMConfig, LayoutLMModel, LayoutLMTokenizer, LayoutLMForSequenceClassification


tokenizer = LayoutLMTokenizer.from_pretrained('microsoft/layoutlm-base-uncased')
model = LayoutLMForSequenceClassification.from_pretrained('microsoft/layoutlm-base-uncased')

words = ["Hello", "[MASK]"]
normalized_word_boxes = [[637, 773, 693, 782], [698, 773, 733, 782]]

token_boxes = []
for word, box in zip(words, normalized_word_boxes):
    word_tokens = tokenizer.tokenize(word)
    token_boxes.extend([box] * len(word_tokens))



token_boxes = [[0, 0, 0, 0]] + token_boxes + [[1000, 1000, 1000, 1000]]
encoding = tokenizer(' '.join(words), return_tensors="pt")
input_ids = encoding["input_ids"]
attention_mask = encoding["attention_mask"]
token_type_ids = encoding["token_type_ids"]
bbox = torch.tensor([token_boxes])
sequence_label = torch.tensor([0,1])

outputs = model(input_ids=input_ids, bbox=bbox, attention_mask=attention_mask, token_type_ids=token_type_ids,labels=sequence_label)


loss = outputs.loss
logits = outputs.logits
pass