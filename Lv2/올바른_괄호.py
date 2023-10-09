def solution(s):
    left = 0
    for c in s:
        if c == '(':
            left += 1
        elif c == ')':
            left -= 1
        
        if left < 0:
            return False

    return left == 0