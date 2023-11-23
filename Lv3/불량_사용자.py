import math

# 제한사항을 충족하지 못하는 경우 False, 충족하는 경우 True
def check_exception(user_id, banned_id, user_id_len_list, banned_id_len_list):
    user_id_list_len = len(user_id)
    banned_id_list_len = len(banned_id)
    
    # 제한사항 예외처리
    # user_id 배열의 크기는 1 이상 8 이하입니다.
    if user_id_list_len < 1 or user_id_list_len > 8:
        return False
    
    # banned_id 배열의 크기는 1 이상 user_id 배열의 크기 이하입니다.
    if banned_id_list_len < 1 or banned_id_list_len > user_id_list_len:
        return False
    
    # 응모한 사용자 아이디들은 서로 중복되지 않습니다.
    if user_id_list_len != len(set(user_id)):
        return False
    
    for i in range(len(user_id)):
        # user_id 배열 각 원소들의 값은 길이가 1 이상 8 이하인 문자열입니다.
        if user_id_len_list[i] < 1 or user_id_len_list[i] > 8:
            is_exception = False
        
        # 응모한 사용자 아이디는 알파벳 소문자와 숫자로만으로 구성되어 있습니다.
        if not user_id[i].isalpha():
            is_exception = False
    
    for i in range(len(banned_id)):
        # banned_id 배열 각 원소들의 값은 길이가 1 이상 8 이하인 문자열입니다.
        if banned_id_len_list[i] < 1 or banned_id_len_list[i] > 8:
            return False
        
        # 불량 사용자 아이디는 '*' 문자를 하나 이상 포함하고 있습니다.
        if banned_id[i].count('*') < 1:
            return False
        
        # 불량 사용자 아이디는 알파벳 소문자와 숫자, 가리기 위한 문자 '*' 로만 이루어져 있습니다.
        for b_i_w in banned_id[i]:
            if not(b_i_w.islower() or b_i_w.isdigit() or b_i_w == '*'):
                return False
    
    return True

def solution(user_id, banned_id):
    banned_id_set = list(set(banned_id))
    banned_id_set_len = len(banned_id_set)
    banned_id_set_len_list = []
    for i in range(banned_id_set_len):
        banned_id_set_len_list.append(len(banned_id_set[i]))
    
    user_id_len = len(user_id)
    banned_id_len = len(banned_id)
    
    user_id_len_list = []
    banned_id_len_list = []
    for i in range(user_id_len):
        user_id_len_list.append(len(user_id[i]))
    for i in range(banned_id_len):
        banned_id_len_list.append(len(banned_id[i]))
    
    # 예외 처리
    if not check_exception(user_id, banned_id, user_id_len_list, banned_id_len_list):
        return
    
    banned_id_num = {}          # banned_id 개수. 중복될 수 있음
    for b_i in banned_id:
        if b_i in banned_id_num.keys():
            banned_id_num[b_i] += 1
        else:
            banned_id_num[b_i] = 1

    restricted_user_id_num = {} # banned_id 후보군 개수
    for b_i_set_element in banned_id_set:
        restricted_user_id_num[b_i_set_element] = 0
    
    for i in range(banned_id_set_len):
        b_i_s_len = banned_id_set_len_list[i]
        
        # "****"와 같이 banned_id가 "*"로만 이루어진 경우
        if b_i_s_len == banned_id_set[i].count('*'):
            for j in range(user_id_len):
                # 길이가 banned_id와 같은 모든 user_id가 대상
                if user_id_len_list[j] == b_i_s_len:
                    restricted_user_id_num[banned_id_set[i]] += 1
        
        else:
            # banned_id 한글자씩 user id와 대조
            for j in range(user_id_len):
                u_i_len = user_id_len_list[j]
                # 제재 대상 id는 banned_id와 길이가 같아야함
                if b_i_s_len != u_i_len:
                    continue
                
                is_restricted_id = True
                k = 0
                while k < b_i_s_len:
                    if banned_id_set[i][k] == "*" or banned_id_set[i][k] == user_id[j][k]:
                        k += 1
                        continue
                    is_restricted_id = False
                    break
                
                if is_restricted_id:
                    restricted_user_id_num[banned_id_set[i]] += 1
                    
    result = 1
    print(banned_id_num)
    print(restricted_user_id_num)
    for k,v in banned_id_num.items():
        print(math.factorial(restricted_user_id_num[k]) / math.factorial(v))
        result *= math.factorial(restricted_user_id_num[k]) / math.factorial(v)
    
    return result

user_id = ["frodo", "fradi", "crodo", "abc123", "frodoc"]
banned_id_list = [
    ["fr*d*", "abc1**"],
    ["*rodo", "*rodo", "******"],
    ["fr*d*", "*rodo", "******", "******"]
]

for banned_id in banned_id_list:
    print(solution(user_id, banned_id))