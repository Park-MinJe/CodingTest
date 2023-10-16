mod = 1234567

def solution(n):
    first = 1
    second = 1
    for i in range(2, n):
        tmp = first+second
        first = second % mod
        second = tmp % mod
    return second