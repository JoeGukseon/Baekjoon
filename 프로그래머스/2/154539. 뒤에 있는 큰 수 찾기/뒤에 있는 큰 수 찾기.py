def solution(numbers):
    answer = [-1] * len(numbers)
    stack = []

    for i in range(len(numbers) - 1, -1, -1):
        while stack and numbers[stack[-1]] <= numbers[i]:
            stack.pop()

        if not stack:
            answer[i] = -1
        else:
            answer[i] = numbers[stack[-1]]

        stack.append(i)

    return answer