import math

def solution(n):
    answer = 0
    max_len = math.floor(-0.5 + math.sqrt(0.25+2*n))
    for i in range(1, max_len+1):
        a = (n-0.5*(i**2))/i + 0.5
        if int(a) == a:
            answer += 1
    return answer