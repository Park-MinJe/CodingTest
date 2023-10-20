def solution(n):
    ans = 1
    
    while True:
        if n == 1:
            break
        
        if n % 2 == 0:
            n /= 2
        else:
            n -= 1
            ans += 1

    return ans