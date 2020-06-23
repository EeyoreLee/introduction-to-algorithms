# -*- encoding: utf-8 -*-
'''
@create_time: 2020/06/23 14:46:16
@author: lichunyu
'''


a = [100, 113, 110, 85, 105, 102, 86, 63, 81, 101, 94, 106, 101, 79, 94, 90, 97]


def convert_list(lst):
    res = []
    for n, i in enumerate(lst[1:]):
        res.append(i-lst[n])
    return res


new_a = convert_list(a)


def get_mid_max_array(lst):
    mid = len(lst)//2
    sublst_l = get_max_lst_l(lst[:mid])
    sublst_r = get_max_lst_r(lst[mid:])
    res = sublst_l+sublst_r
    return res


def get_max_lst_l(lst):
    res = []
    s = 0
    s_tmp = 0
    for i in range(-1, -len(lst), -1):
        s_tmp += lst[i]
        if s_tmp >= s:
            res = lst[i:]
            s = s_tmp
    # if not isinstance(res, list):
    #     res = []
    return res


def get_max_lst_r(lst):
    res = []
    s = 0
    s_tmp = 0
    for i in range(len(lst)):
        s_tmp += lst[i]
        if s_tmp >= s:
            res = lst[:i+1]
            s = s_tmp
    # if not isinstance(res, list):
    #     res = []
    return res


def sum_array(lst):
    s = 0
    for i in lst:
        s += i
    return s


def get_max_subarray(lst):
    if len(lst) == 1:
        return lst
    mid_subarray = get_mid_max_array(lst)
    mid = len(lst)//2
    left_subarray = get_max_subarray(lst[:mid])
    right_subarray = get_max_subarray(lst[mid:])
    sum_mid_subarray = sum_array(mid_subarray)
    sum_left_subarray = sum_array(left_subarray)
    sum_right_subarray = sum_array(right_subarray)
    if sum_mid_subarray >= sum_left_subarray and sum_mid_subarray >= sum_right_subarray:
        return mid_subarray
    elif sum_left_subarray >= sum_mid_subarray and sum_left_subarray >= sum_right_subarray:
        return left_subarray
    elif sum_right_subarray >= sum_mid_subarray and sum_right_subarray >= sum_left_subarray:
        return right_subarray


max_subarray = get_max_subarray(new_a)
print(max_subarray)