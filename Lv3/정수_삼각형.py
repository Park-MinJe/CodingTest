def solution(triangle):
    triangle[0] = [0] + triangle[0] + [0]
    for i in range(1, len(triangle)):
        triangle[i] = [0] + triangle[i] + [0]
        for j in range(1, i+2):
            triangle[i][j] += max(triangle[i-1][j-1], triangle[i-1][j])
    return max(triangle[-1])

'''
def solution(triangle):
    for i in range(1, len(triangle)):
        row_len = len(triangle[i])
        for j in range(0, row_len):
            if j == 0:
                triangle[i][j] += triangle[i-1][j]
            elif j == row_len-1:
                triangle[i][j] += triangle[i-1][j-1]
            else:
                triangle[i][j] += triangle[i-1][j-1] if triangle[i-1][j-1]>triangle[i-1][j] else triangle[i-1][j]
    return max(triangle[-1])
'''