def solution(n, left, right):
    answer = [0] * (right - left + 1)
    for i in range(left, right + 1):
        answer[i - left] = max(i // n, i % n) + 1
    return answer