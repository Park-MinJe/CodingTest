import math
def solution(n,a,b):
    answer = 0

    for i in range(int(math.log2(n))+1):
        a = math.ceil(a/2.0)
        b = math.ceil(b/2.0)
        if a == b:
            answer = i+1
            break

    return answer