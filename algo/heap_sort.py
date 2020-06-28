# -*- encoding: utf-8 -*-
'''
@create_time: 2020/06/23 18:33:38
@author: lichunyu
'''


# def heapify(length, lst, i):
#     """判断复杂"""
#     heap_l = 2*i + 1
#     heap_r = 2*i + 2

#     if heap_l < length and lst[heap_l] > lst[i] and (heap_r >= length or lst[heap_l] >= lst[heap_r]):
#         lst[heap_l], lst[i] = lst[i], lst[heap_l]
#         heapify(length, lst, heap_l)

#     elif heap_r < length and lst[heap_r] > lst[i] and lst[heap_r] >= lst[heap_l]:
#         lst[heap_r], lst[i] = lst[i], lst[heap_r]
#         heapify(length, lst, heap_r)


def heapify(length, lst, i):
    """简化"""
    heap_l = 2*i + 1
    heap_r = 2*i + 2

    _max = i

    if heap_l < length and lst[heap_l] > lst[i]:
        _max = heap_l

    if heap_r < length and lst[heap_r] > lst[_max]:
        _max = heap_r

    if _max != i:
        lst[i], lst[_max] = lst[_max], lst[i]
        heapify(length, lst, _max)


def heap_sort(lst):
    length = len(lst)
    for i in range(length//2-1, -1, -1):
        heapify(length, lst, i)
    for j in range(length-1, -1, -1):
        lst[0], lst[j] = lst[j], lst[0]
        heapify(j, lst, 0)

    return lst


if __name__ == '__main__':
    import random
    lst = list(range(20))
    random.shuffle(lst)
    res = heap_sort(lst)
    print(res)
