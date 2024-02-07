def solution(number, k):
    stack = []
    for digit in number:
        while k > 0 and stack and stack[-1] < digit:
            stack.pop()
            k -= 1
        stack.append(digit)

    result = ''.join(stack[:len(stack) - k])
    return result