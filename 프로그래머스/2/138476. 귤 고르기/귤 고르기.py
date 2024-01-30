def solution(k, tangerine):
    answer = 0
    fruit_count = {}

    for i in tangerine:
        fruit_count[i] = fruit_count.get(i, 0) + 1

    sorted_fruits = sorted(fruit_count.items(), key=lambda x: x[1], reverse=True)

    for fruit, count in sorted_fruits:
        if k <= 0:
            break
        answer += 1
        k -= count

    return answer