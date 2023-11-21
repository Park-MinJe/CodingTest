def string_to_list(s):
    l = []
    sub_l = []
    
    s = s[1:-1]
    brace = 0
    head = 0
    for i in range(len(s)):
        if s[i] == '{':
            brace += 1
        if s[i] == '}':
            brace -= 1
        
        if brace == 0 and s[i] == ',':
            sub_l = s[head+1:i-1].split(',')
            l.append(sub_l)
            head = i+1
        if i == len(s)-1:
            sub_l = s[head+1:-1].split(',')
            l.append(sub_l)
            head = i+1
    return l

def sort_by_len(set_list):
    for i in range(len(set_list)-1, 0, -1):
        for j in range(i):
            sub_len = len(set_list[j])
            target_len = len(set_list[j+1])
            if sub_len > target_len:
                set_list[j], set_list[j+1] = set_list[j+1], set_list[j]

def solution(s):
    set_list = string_to_list(s)
    sort_by_len(set_list)
    
    answer = [int(set_list[0][0])]
    for i in range(1, len(set_list)):
        complement = list(set(set_list[i]) - set(set_list[i-1]))
        answer.append(int(complement[0]))
    return answer