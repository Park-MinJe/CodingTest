from collections import deque


def solution(queue1, queue2):
    answer = 0
    queue1 = deque(queue1)
    queue2 = deque(queue2)
    limit = (len(queue1)) * 4
    tot1 = sum(queue1)
    tot2 = sum(queue2)
    total = tot1 + tot2

    if total % 2 != 0:
        return -1

    while True:
        if tot1 > tot2:
            target = queue1.popleft()
            queue2.append(target)
            tot1 -= target
            tot2 += target
            answer += 1
        elif tot1 < tot2:
            target = queue2.popleft()
            queue1.append(target)
            tot1 += target
            tot2 -= target
            answer += 1
        else:
            break
        if answer == limit:
            answer = -1
            break
    return answer

queue1_list = [
    [3, 2, 7, 2],
    [1, 2, 1, 2],
    [1, 1]
]
queue2_list = [
    [4, 6, 5, 1],
    [1, 10, 1, 2],
    [1, 5]
]
for i in range(len(queue1_list)):
    print(solution(queue1_list[i], queue2_list[i]))