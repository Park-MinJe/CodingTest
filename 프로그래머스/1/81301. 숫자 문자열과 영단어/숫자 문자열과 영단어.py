def solution(s):
    num_to_word_tab = [
        "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
    ]
    
    if s.isdigit():
        return int(s)
    
    answer = ""
    i = 0
    while i < len(s):
        word_len = 1
        
        if s[i].isdigit():
            answer = answer + s[i]
        elif s[i] == 'z':
            answer = answer + "0"
            word_len = len(num_to_word_tab[0])
        elif s[i] == 'o':
            answer = answer + "1"
            word_len = len(num_to_word_tab[1])
        elif s[i] == 't':
            if s[i+1] == 'w':
                answer = answer + "2"
                word_len = len(num_to_word_tab[2])
            elif s[i+1] == 'h':
                answer = answer + "3"
                word_len = len(num_to_word_tab[3])
        elif s[i] == 'f':
            if s[i+1] == 'o':
                answer = answer + "4"
                word_len = len(num_to_word_tab[4])
            elif s[i+1] == 'i':
                answer = answer + "5"
                word_len = len(num_to_word_tab[5])
        elif s[i] == 's':
            if s[i+1] == 'i':
                answer = answer + "6"
                word_len = len(num_to_word_tab[6])
            elif s[i+1] == 'e':
                answer = answer + "7"
                word_len = len(num_to_word_tab[7])
        elif s[i] == 'e':
            answer = answer + "8"
            word_len = len(num_to_word_tab[8])
        elif s[i] == 'n':
            answer = answer + "9"
            word_len = len(num_to_word_tab[9])
        
        i += word_len
        if i == len(s): break
    return int(answer)