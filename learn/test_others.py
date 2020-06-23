from math import log, exp


def logsumexp(A):
    k = max(A)
    return log(sum(exp(i-k) for i in A))+k


def _exp(a):
    k =  max(a)
    res = sum(exp(i-k) for i in a)
    pass

if __name__ == "__main__":
    a = [1,3,4,5,2]
    # res = logsumexp(a)
    res = _exp(a)
    pass