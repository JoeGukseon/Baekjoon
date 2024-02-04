def solution(s):
    answer = 0
    for i in range(len(s)):
        if i != 0:
            s = s[1:] + s[0]
        answer += 1
        stack = []
        for ch in s:
            if ch in ['(', '[', '{']:
                stack.append(ch)
            elif ch in [')', ']', '}']:
                if not stack:
                    answer -= 1
                    break
                top = stack.pop()
                if (ch == ')' and top != '(') or (ch == ']' and top != '[') or (ch == '}' and top != '{'):
                    answer -= 1
                    stack.clear()
                    break
        if stack:
            answer -= 1
    return answer