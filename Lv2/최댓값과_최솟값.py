def solution(s):
    answer = ""
    
    nums = s.split()
    min_num = int(nums[0])
    max_num = int(nums[0])
    for i in range(1, len(nums)):
        n = int(nums[i])
        if min_num > n:
            min_num = n
        if max_num < n:
            max_num = n
    
    answer += str(min_num) + ' ' + str(max_num)
    
    return answer

'''
def solution(s):
    s = list(map(int,s.split()))
    return str(min(s)) + " " + str(max(s))
'''