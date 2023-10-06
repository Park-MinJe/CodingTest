def solution(targets):
    answer = 0
    
    targets.sort(key=lambda x : x[1])
    lazer = -1
    for target in targets:
        if target[0] >= lazer:
            answer+=1
            lazer = target[1] - 0.5
    
    return answer

targets = [[4,5],[4,8],[10,14],[11,13],[5,12],[3,7],[1,4]]

print(solution(targets))