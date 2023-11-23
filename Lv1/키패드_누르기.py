key_pad = [
    ["1", "2", "3"],
    ["4", "5", "6"],
    ["7", "8", "9"],
    ["*", "0", "#"]
]

def find_idx(key):
    for i in range(len(key_pad)):
        for j in range(len(key_pad[i])):
            if key_pad[i][j] == key:
                return [i, j]
'''
from_idx: [row, col]
to_idx  : [row, col]
'''
def check_distance(from_idx, to_idx):
    return abs(to_idx[0] - from_idx[0]) + abs(to_idx[1] - from_idx[1])
    
'''
cur_num: 현재 손가락이 위치한 숫자
next_num: 다음에 누를 숫자
int_hand: 0은 "left", 1은 "right"
'''
def select_hand(next_num, int_hand, left_finger_pos, right_finger_pos):
#def select_hand(next_num, int_hand):
    if next_num % 3 == 1:
        tmp_pos = find_idx(str(next_num))
        left_finger_pos[0] = tmp_pos[0]
        left_finger_pos[1] = tmp_pos[1]
        return "L"
    elif next_num % 3 == 0 and next_num != 0:
        tmp_pos = find_idx(str(next_num))
        right_finger_pos[0] = tmp_pos[0]
        right_finger_pos[1] = tmp_pos[1]
        return "R"
    else:
        next_num_pos = find_idx(str(next_num))
        left_dist = check_distance(left_finger_pos, next_num_pos)
        right_dist = check_distance(right_finger_pos, next_num_pos)

        if left_dist < right_dist:
            left_finger_pos[0] = next_num_pos[0]
            left_finger_pos[1] = next_num_pos[1]
            return "L"
        elif left_dist > right_dist:
            right_finger_pos[0] = next_num_pos[0]
            right_finger_pos[1] = next_num_pos[1]
            return "R"
        else:
            if int_hand == 0:   # left
                left_finger_pos[0] = next_num_pos[0]
                left_finger_pos[1] = next_num_pos[1]
                return "L"
            elif int_hand == 1: # right
                right_finger_pos[0] = next_num_pos[0]
                right_finger_pos[1] = next_num_pos[1]
                return "R"
            
    
def solution(numbers, hand):
    left_finger_pos = [3, 0]
    right_finger_pos = [3, 2]
    
    int_hand = 0
    if hand == "right": int_hand = 1
    
    answer = select_hand(numbers[0], int_hand, left_finger_pos, right_finger_pos)
    for i in range(1, len(numbers)):
        answer += select_hand(numbers[i], int_hand, left_finger_pos, right_finger_pos)
    return answer

numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
hand = "right"
print(solution(numbers, hand))