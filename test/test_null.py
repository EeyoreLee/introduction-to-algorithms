# -*- encoding: utf-8 -*-
'''
@create_time: 2020/05/29 17:55:25
@author: lichunyu
'''



def test():
    if None:
        none = 'fail'
    else:
        none = 'success'
    if '':
        kong = 'fail'
    else:
        kong = 'success'

    res = [none, kong]

    return res


if __name__ == "__main__":
    test()