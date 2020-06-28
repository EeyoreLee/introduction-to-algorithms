# -*- encoding: utf-8 -*-
'''
@create_time: 2020/06/28 10:02:36
@author: lichunyu
'''


import requests

url = 'http://47.102.252.183:8100/rpa/invoice_extract'
files = {'file': open('/Users/lichunyu/Downloads/百胜电子发票.pdf', 'rb')}
res = requests.post(url=url, files=files)
pass