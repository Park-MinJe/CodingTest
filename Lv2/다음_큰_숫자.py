from collections import Counter
def to_binary(n):
    return format(n, 'b')

def count_one(n):
    n = to_binary(n)
    n = Counter(list(n))
    return n['1']

def solution(n):
    cnt = count_one(n)
    for i in range(n+1, 1000001): 
    # 1. n의 2진수시에 1의 갯수 확인 
        if cnt == (count_one(i)): return i