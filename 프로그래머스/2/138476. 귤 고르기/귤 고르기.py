def solution(k, tangerine):
    tangerine_set = set(tangerine)
    tangerine_dict = dict()
    for ts in tangerine_set:
        tangerine_dict[ts] = 0
    for t in tangerine:
        tangerine_dict[t] += 1
    sorted_dict = sorted(tangerine_dict.items(), key = lambda item:item[1], reverse = True)
    
    for i in range(len(sorted_dict)):
        type_cnt = sorted_dict[i][1]
        if type_cnt >= k:
            return i+1
        k -= type_cnt
    
    return len(list(tangerine_set))