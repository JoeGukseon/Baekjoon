def solution(s):
    stack = []

    try:
        for c in s:
            if c == '(':
                stack.append(c)
            else:
                stack.pop()
    except IndexError:
        return False

    return not stack