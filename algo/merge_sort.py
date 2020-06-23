# -*- encoding: utf-8 -*-
'''
@create_time: 2020/06/22 13:50:50
@author: lichunyu
'''
import random


def merge(lst_l, lst_r, max_num=99999):
    lst_l.append(max_num)
    lst_r.append(max_num)
    res = []
    while lst_l[0]!=max_num or lst_r[0]!=max_num:
        l = lst_l[0]
        r = lst_r[0]
        if l < r:
            res.append(l)
            lst_l = lst_l[1:]
        elif r < l:
            res.append(r)
            lst_r = lst_r[1:]
        elif l == r:
            res.extend([l, r])
            lst_l = lst_l[1:]
            lst_r = lst_r[1:]
    return res


def merge_sort(lst):
    r = len(lst)
    if r == 1:
        return lst
    q = r//2
    lst_l = merge_sort(lst[:q])
    lst_r = merge_sort(lst[q:])
    return merge(lst_l, lst_r)


if __name__ == '__main__':
    # lst = [1, 3, 5, 2, 4, 6]
    # res = merge(lst, 0, 3, 6)
    lst = list(range(10))
    random.shuffle(lst)
    res = merge_sort(lst)
    print(res)