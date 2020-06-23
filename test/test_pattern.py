# -*- encoding: utf-8 -*-
'''
@create_time: 2020/05/27 17:43:45
@author: lichunyu
'''

import re


def test(content):
    # pattern1 = re.compile('董事(?!物理).*')
    # pattern1 = re.compile('董事长.*')
    # pattern1 = re.compile('^.*?(?!总).经理行使以下职权')
    # pattern1 = re.compile('((?!总).)+(经理行使以下职权)')
    # pattern1 = re.compile('第[0-9一二三四五六七八九十百千]{1,7}条')
    pattern1 = re.compile('简要案情或者报案记录.{0,40}证据[:：]+(.*)')

    res = pattern1.search(content)

    return res


if __name__ == '__main__':
    content = '12019年7月10日'
    test(content)
    pass
