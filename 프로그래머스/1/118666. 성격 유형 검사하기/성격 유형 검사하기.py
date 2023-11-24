def solution(survey, choices):
    # 총 타입의 종류
    types = {
        'R': 0, 'T': 0,
        'C': 0, 'F': 0,
        'J': 0, 'M': 0,
        'A': 0, 'N': 0
    }
    priority = ['R', 'C', 'J', 'A']
    
    survey_size = len(survey)
    for i in range(survey_size):
        if choices[i] == 4:
            continue
        if choices[i] < 4:
            types[survey[i][0]] += 4 - choices[i]
            continue
        if choices[i] > 4:
            types[survey[i][1]] += choices[i] - 4
    
    answer = ""
    keys = list(types.keys())
    i = 0
    while i < len(keys):
        if types[keys[i]] > types[keys[i+1]]:
            answer += keys[i]
        elif types[keys[i]] < types[keys[i+1]]:
            answer += keys[i+1]
        else:
            answer += priority[int(i/2)]
        i += 2
    return answer