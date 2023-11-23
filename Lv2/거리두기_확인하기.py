# 제한사항 검증
# 방의 수가 5개인지 검증
def is_exception_of_room_num(places):
    # 대기실 개수 = 5
    return len(places) != 5

# 대기실의 세로 길이 = 5 검증
def is_exception_of_row_num(place):
    return len(place) != 5

# 대기실의 가로 길이 = 5 검증
def is_exception_of_col_num(row):
    return len(row) != 5

# 문자가 P, O, X인지 검증
def is_exception_of_alphabet(alpha):
    keyword = ["P", "O", "X"]
    return not alpha in keyword

'''
person_pos_1 = (row, col)
person_pos_2 = (row, col)
'''
def calc_menhattan(person_pos_1, person_pos_2):
    return abs(person_pos_1[0]-person_pos_2[0]) + abs(person_pos_1[1]-person_pos_2[1])

def solution(places):
    answer = []
    if is_exception_of_room_num(places):
        return answer
    
    for place in places:
        if is_exception_of_row_num(place):
            answer.append(0)
            continue
            
        people_pos_list = []
        row = 0
        is_col_num_exception = False
        is_alphabet_exception = False
        while row < len(place):
            # 대기실 가로 길이 검증
            if is_exception_of_col_num(place[row]):
                is_col_num_exception = True
                answer.append(0)
            if is_col_num_exception:
                break
                
            col = 0
            while col < len(place[row]):
                # 문자가 P, O, X인지 검증
                if is_exception_of_alphabet(place[row][col]):
                    is_alphabet_exception = True
                    answer.append(0)
                if is_alphabet_exception:
                    break
                
                # 사람의 위치 인덱스 저장
                if place[row][col] == "P":
                    people_pos_list.append((row, col))
                col += 1
                
            # 문자가 P, O, X인지 검증 결과 오류 검출시 다음 대기실로 넘어가야함
            if is_alphabet_exception:
                break
            row += 1
            
        # 검증 결과 오류 검출시 다음 대기실로 넘어가야함
        if is_col_num_exception or is_alphabet_exception:
            continue
        
        # 사람이 없으면 거리두기를 지키고 있는 것이다
        if len(people_pos_list) == 0:
            answer.append(1)
            continue
        
        # 맨해튼 거리가 2 이하인 쌍을 구한다
        is_menhattan_dist_one = False
        validation_target_pairs = []
        for i in range(len(people_pos_list)):
            for j in range(i+1, len(people_pos_list)):
                menhattan_dist = calc_menhattan(people_pos_list[i], people_pos_list[j])
                # 맨해튼 거리가 1인 경우, 거리두기를 지키지 않은 것이다.
                if menhattan_dist == 1:
                    is_menhattan_dist_one = True
                    break
                # 맨해튼 거리가 2인 경우, 검증이 필요하다.
                if menhattan_dist == 2:
                    validation_target_pairs.append((people_pos_list[i], people_pos_list[j]))
            if is_menhattan_dist_one:
                break
        # 맨해튼 거리가 1인 경우, 거리두기를 지키지 않은 것이다.
        if is_menhattan_dist_one:
            answer.append(0)
            continue
        
        # 맨해튼 거리가 2인 경우, 검증이 필요하다.
        is_validation_failed = False
        for validation_target_pair in validation_target_pairs:
            person_1_pos = validation_target_pair[0]
            person_2_pos = validation_target_pair[1]
            
            if person_1_pos[0] == person_2_pos[0]:
                if place[person_1_pos[0]][min(person_1_pos[1],person_2_pos[1])+1] == "O":
                    answer.append(0)
                    is_validation_failed = True
                    break
                continue
            if person_1_pos[1] == person_2_pos[1]:
                if place[min(person_1_pos[0],person_2_pos[0])+1][person_1_pos[1]] == "O":
                    answer.append(0)
                    is_validation_failed = True
                    break
                continue
            
            # 두 사람이 서로 대각선 상에 위치하는 경우
            if place[person_1_pos[0]][person_2_pos[1]] == "O" or place[person_2_pos[0]][person_1_pos[1]] == "O":
                answer.append(0)
                is_validation_failed = True
                break
        if not is_validation_failed:
            answer.append(1)
    
    return answer

places = [["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"], ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"], ["PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"], ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"], ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"]]
print(solution(places))