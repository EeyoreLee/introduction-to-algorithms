# -*- encoding: utf-8 -*-
'''
@create_time: 2020/06/28 17:21:32
@author: lichunyu
'''


def _quick_sort(lst, p, r):
    if p < r-1:
        m = partition(lst, p ,r)
        _quick_sort(lst, p, m)
        _quick_sort(lst, m+1, r)


def quick_sort(lst):
    _quick_sort(lst, 0, len(lst))
    return lst


def partition(lst, p, r):
    mark = lst[p]
    i = p
    for j in range(p+1, r):
        if lst[j] < mark:
            i += 1
            lst[i], lst[j] = lst[j], lst[i]
    lst[i], lst[p] = lst[p], lst[i]
    return i


if __name__ == '__main__':
    import random
    lst = list(range(20))
    random.shuffle(lst)
    res = quick_sort(lst)
    print(res)
