# -*- encoding: utf-8 -*-
'''
@create_time: 2020/06/29 11:21:05
@author: lichunyu
'''


def bucket_sort(lst, e=10):
    _min = min(lst)
    _max = max(lst)
    l = _max - _min
    buckets = [[] for i in range(e+1)]
    for i in lst:
        m = int((i - _min) // (l/e))
        mark = False
        for n, j in enumerate(buckets[m]):
            if j > i:
                buckets[m] = insert(i, n, buckets[m])
                mark = True
                break
        if mark is False:
            buckets[m].append(i)
    res = [_ for b in buckets for _ in b]
    return res


def insert(i, n, lst):
    return lst[:n] + [i] + lst[n:]


if __name__ == '__main__':
    import random
    lst = list(range(20))
    random.shuffle(lst)
    res = bucket_sort(lst)
    print(res)