import numpy as np


# def forward_v():
def get_data():
    data = {}
    with open('data.txt', 'r', encoding='utf-8') as f:
        fl = f.read().splitlines()
        for fl_i in fl:
            x = ''
            y = ''
            for n in range(len(fl_i)//3):
                x += fl_i[n*3]
                y += fl_i[n*3+2]
            data[x] = y
    return data


def fun_f(y1, y2, x, i):
    """"""

    return 1

if __name__ == '__main__':
    get_data()
    pass
