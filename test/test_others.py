import requests


url = 'http://ysocr.datagrand.cn/ysocr/ocr'
files = {'file': open('/Users/lichunyu/Downloads/百胜电子发票.pdf', 'rb')}
r = requests.post(url=url, files=files)
pass