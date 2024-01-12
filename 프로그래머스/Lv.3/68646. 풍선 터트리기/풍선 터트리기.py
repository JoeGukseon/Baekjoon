def solution(a):
    n = len(a)
    if n == 1:
        return 1

    left_min = [0] * n
    min_to_left = a[0]

    right_min = [0] * n
    min_to_right = a[n - 1]

    for i in range(1, n - 1):
        min_to_left = min(min_to_left, a[i])
        left_min[i] = min_to_left

        min_to_right = min(min_to_right, a[n - 1 - i])
        right_min[n - 1 - i] = min_to_right

    answer = 2

    for i in range(1, n - 1):
        if a[i] > left_min[i] and a[i] > right_min[i]:
            continue
        answer += 1

    return answer