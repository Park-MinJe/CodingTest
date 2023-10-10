def solution(s):
    remove_zero_cnt = 0
    repeat_cnt = 0
    
    while s != "1":
        repeat_cnt+=1
        
        sorted_s = ''.join(sorted(s))
        s_to_int = int(sorted_s)
        s_to_int_len = len(str(s_to_int))
        remove_zero_cnt += len(s) - s_to_int_len
        
        s = format(s_to_int_len, "b")
    
    return [repeat_cnt, remove_zero_cnt]