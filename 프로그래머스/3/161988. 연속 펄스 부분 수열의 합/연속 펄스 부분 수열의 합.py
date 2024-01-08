def solution(sequence):
    answer = 0
    is_plus = True
    purse1, purse2 = 0, 0

    for num in sequence:
        purse1 += num if is_plus else -num
        purse2 += -num if is_plus else num

        purse1 = max(0, purse1)
        purse2 = max(0, purse2)

        answer = max(answer, max(purse1, purse2))

        is_plus = not is_plus

    return answer
