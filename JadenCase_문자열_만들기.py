def solution(s):
    answer = ''
    s = s.split(' ')
    for i in range(0, len(s)):
        s[i] = s[i].lower().capitalize()
    return ' '.join(s)