# -*- encoding: utf-8 -*-
'''
@create_time: 2020/06/29 10:51:43
@author: lichunyu
'''


def randix_sort(lst, r=''):
    if r == '':
        r = 1
        for i in lst:
            tmp_r = len(str(i))
            if tmp_r > r:
                r = tmp_r
    for i in range(r):
        buckets = [[] for i in range(10)]
        for j in lst:
            buckets[j//(10**i) % 10].append(j)
        lst = [_ for b in buckets for _ in b]
    return lst


if __name__ == '__main__':
    import random
    lst = list(range(20))
    random.shuffle(lst)
    res = randix_sort(lst)
    print(res)
