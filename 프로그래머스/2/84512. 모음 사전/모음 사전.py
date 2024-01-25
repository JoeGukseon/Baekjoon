def solution(word):
    val = [781, 156, 31, 6, 1]
    answer = len(word)

    for i in range(len(word)):
        char = word[i]
        if char == 'A':
            idx = 0
        elif char == 'E':
            idx = 1
        elif char == 'I':
            idx = 2
        elif char == 'O':
            idx = 3
        elif char == 'U':
            idx = 4
        else:
            idx = -1

        if idx != -1:
            answer += val[i] * idx

    return answer