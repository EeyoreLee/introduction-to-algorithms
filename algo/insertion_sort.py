# -*- encoding: utf-8 -*-
'''
@create_time: 2020/06/22 11:50:59
@author: lichunyu
'''


def insertion_sort(lst):
    for i in range(1, len(lst)):
        j = i - 1
        while j >= 0 and lst[j] > lst[i]:
            lst[i], lst[j] = lst[j], lst[i]
            i = j
            j -= 1
    return lst


if __name__ == '__main__':
    a = [5, 2, 4, 6, 1, 7, 3, 9, 8]
    b = insertion_sort(a)
    print(b)
