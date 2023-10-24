def is_disjoint(iNum1, iNum2):
    for i in sorted(range(2, min(iNum1, iNum2)+1), reverse=True):
        if iNum1%i==0 and iNum2%i==0:
            return [False, i] # 공통된 정수로 나눠지면 서로소가 아님. [false, i] 반환
    return [True, 0] # 두 수가 서로소인경우 [true, 0] 반환

def calc_lcm(iNum1, iNum2): # 두 수의 최소공배수 구하기
    lcm = 1
    
    is_disjoint_and_divide_num = is_disjoint(iNum1, iNum2)
    while not is_disjoint_and_divide_num[0]:
        lcm *= is_disjoint_and_divide_num[1]
        
        iNum1 //= is_disjoint_and_divide_num[1]
        iNum2 //= is_disjoint_and_divide_num[1]
        is_disjoint_and_divide_num = is_disjoint(iNum1, iNum2)
    return lcm * iNum1 * iNum2

def solution(arr):
    if len(arr) == 1: return arr[0]
    
    answer = calc_lcm(arr[0], arr[1])
    for i in range(2, len(arr)):
        answer = calc_lcm(answer, arr[i])
    return answer