'''
"U X"   : 현재 선택된 행에서 X칸 위에 있는 행을 선택합니다.
"D X"   : 현재 선택된 행에서 X칸 아래에 있는 행을 선택합니다.
"C"     : 현재 선택된 행을 삭제한 후, 바로 아래 행을 선택합니다. 단, 삭제된 행이 가장 마지막 행인 경우 바로 윗 행을 선택합니다.
"Z"     : 가장 최근에 삭제된 행을 원래대로 복구합니다. 단, 현재 선택된 행은 바뀌지 않습니다.
'''

def solution(n, k, cmd):
    answer = list("O" * n)
    ptr = k
    #print(ptr)
    #print(answer)

    deleted_stack = []
    for c in cmd:
        #print(answer)
        c_tok = c.split(" ")
        #print(c_tok)
        #print(ptr)
        
        if len(c_tok) == 1:
            if c_tok[0] == "C":
                answer[ptr] = "X"
                deleted_stack.append(ptr)
                if "O" in answer[ptr+1:] and ptr != n-1:
                    ptr = ptr+1 + answer[ptr+1:].index("O")
                else:
                    ptr = ptr-1 - list(reversed(answer[:ptr])).index("O")
                continue
            if c_tok[0] == "Z":
                resotre_ptr = deleted_stack.pop()
                answer[resotre_ptr] = "O"
                continue
        elif len(c_tok) == 2:
            move_size = int(c_tok[1])
            move_cnt = 0
            if c_tok[0] == "U":
                for i in range(ptr-1, -1, -1):
                    ptr -= 1
                    if answer[i] == "O":
                        move_cnt += 1
                    if move_cnt == move_size:
                        break
                continue
            if c_tok[0] == "D":
                for i in range(ptr+1, n):
                    ptr += 1
                    if answer[i] == "O":
                        move_cnt += 1
                    if move_cnt == move_size:
                        break
                continue
    return ''.join(answer)