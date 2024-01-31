def solution(topping):
    answer = 0
    count_map = {}
    unique_set = set()

    for i in topping:
        count_map[i] = count_map.get(i, 0) + 1

    for i in topping:
        count_map[i] -= 1
        unique_set.add(i)
        if count_map[i] == 0:
            del count_map[i]
        if len(count_map) == len(unique_set):
            answer += 1

    return answer