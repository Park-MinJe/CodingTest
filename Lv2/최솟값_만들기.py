def solution(A,B):
    answer = 0
    
    A.sort()
    B.sort(reverse=True)

    for i in range(0, len(A)):
        answer += A[i]*B[i]

    return answer

# test
A = [[1, 4, 2], [1,2]]
B = [[5, 4, 4], [3,4]]

for i in range(0, len(A)):
    print(solution(A[i], B[i]))