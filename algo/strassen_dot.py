# -*- encoding: utf-8 -*-
'''
@create_time: 2020/06/23 15:13:32
@author: lichunyu
'''


def _add(A, B):
    res = []
    for i, j in zip(A,B):
        rows = []
        for a, b in zip(i, j):
            rows.append(a+b)
        res.append(rows)
    return res


def _minus(A, B):
    res = []
    for i, j in zip(A,B):
        rows = []
        for a, b in zip(i, j):
            rows.append(a-b)
        res.append(rows)
    return res


def pre_convert(A):
    x = len(A)
    y = len(A[0])
    if x==y and is_2(x):
        return A
    _max = x if x >=y else y
    l = get_2(_max)
    c = []
    for i in range(l):
        r = []
        for j in range(l):
            if y > j and x > i:
                r.append(A[i][j])
            else:
                r.append(0)
        c.append(r)
    return c


def strassen(A, B):
    if len(A)==1:
        return [[A[0][0]*B[0][0]]]
    else:
        la = len(A)
        lb = len(B)
        A11 = split_matrix(A, 1, la/2, 1, la/2)
        A12 = split_matrix(A, 1, la/2, la/2+1, la)
        A21 = split_matrix(A, la/2+1, la, 1, la/2)
        A22 = split_matrix(A, la/2+1, la, la/2+1, la)
        B11 = split_matrix(B, 1, lb/2, 1, lb/2)
        B12 = split_matrix(B, 1, lb/2, lb/2+1, lb)
        B21 = split_matrix(B, lb/2+1, lb, 1, lb/2)
        B22 = split_matrix(B, lb/2+1, lb, lb/2+1, lb)
        S1 = _minus(B12, B22)
        S2 = _add(A11, A12)
        S3 = _add(A21, A22)
        S4 = _minus(B21, B11)
        S5 = _add(A11, A22)
        S6 = _add(B11, B22)
        S7 = _minus(A12, A22)
        S8 = _add(B21, B22)
        S9 = _minus(A11, A21)
        S10 = _add(B11, B12)
        P1 = strassen(A11, S1)
        P2 = strassen(S2, B22)
        P3 = strassen(S3, B11)
        P4 = strassen(A22, S4)
        P5 = strassen(S5, S6)
        P6 = strassen(S7, S8)
        P7 = strassen(S9, S10)
        C11 = _add(_minus(_add(P5, P4), P2), P6)
        C12 = _add(P1, P2)
        C21 = _add(P3, P4)
        C22 = _minus(_minus(_add(P5, P1), P3), P7)
        C = cat_4_matrix(C11, C12, C21, C22)
        return C


def split_matrix(A, x1, x2, y1, y2):
    res = []
    for r in A[int(x1-1):int(x2)]:
        res.append(r[int(y1-1):int(y2)])
    return res


def cat_4_matrix(C11, C12, C21, C22):
    res_top = []
    for c11, c12 in zip(C11, C12):
        res_top.append(c11 + c12)
    res_botton = []
    for c21, c22 in zip(C21, C22):
        res_botton.append(c21 + c22)
    return res_top + res_botton


def is_2(x):
    if x == 1:
        return False
    for i in bin(x)[3:]:
        if int(i) == 1:
            return False
    return True


def get_2(x):
    if is_2(x):
        return x
    else:
        return int('0b1' + (len(bin(x))-2)*'0', 2)


def strassen_dot(A, B):
    ra = len(A)
    ca = len(A[0])
    rb = len(B)
    cb = len(B[0])
    if ca != rb:
        raise Exception('傻逼，这俩矩阵能乘？？？？')
    A = pre_convert(A)
    B = pre_convert(B)
    res_with_others = strassen(A, B)
    res = split_matrix(res_with_others, 1, ra, 1, cb)
    return res


if __name__ == '__main__':
    a = [[1, 2, 3], [1, 2, 3]]
    b = [[1, 1], [2, 2], [3, 3]]
    res = strassen_dot(a, b)
    print(res)

