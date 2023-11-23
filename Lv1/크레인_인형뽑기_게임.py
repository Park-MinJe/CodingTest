class Stack_Board:
    def __init__(self, pBoard):
        board_size = len(pBoard)
        self.board = []
        for col in range(board_size):
            tmp_col = []
            for row in reversed(range(board_size)):
                item = pBoard[row][col]
                if item != 0:
                    tmp_col.append(item)
            self.board.append(tmp_col)
        
    def pop_by_line_idx(self, p_line_idx):
        if len(self.board[p_line_idx]) == 0:
            return -1
        
        rt = self.board[p_line_idx][-1]
        self.board[p_line_idx] = self.board[p_line_idx][:-1]
        return rt
    
class Bucket:
    def __init__(self):
        self.bucket_stack = []
        self.poped_cnt = 0
    
    def push(self, item_id):
        if len(self.bucket_stack) > 0 and self.bucket_stack[-1] == item_id:
            self.poped_cnt += 2
            self.bucket_stack = self.bucket_stack[:-1]
        else:
            self.bucket_stack.append(item_id)
    
    def get_poped_cnt(self):
        return self.poped_cnt

def solution(board, moves):
    sb = Stack_Board(board)
    b = Bucket()
    for m in moves:
        item = sb.pop_by_line_idx(m-1)
        #print(sb.board)
        if item == -1:
            continue
        b.push(item)
    return b.get_poped_cnt()

board = [[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]]
moves = [1,5,3,5,1,2,1,4]
print(solution(board, moves))