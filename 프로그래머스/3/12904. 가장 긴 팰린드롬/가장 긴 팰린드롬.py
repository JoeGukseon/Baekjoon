def solution(s):
    n = len(s)
    
    dp = [[False] * n for _ in range(n)]

    for i in range(n):
        dp[i][i] = True

    longest_length = 1

    for i in range(n - 1):
        if s[i] == s[i + 1]:
            dp[i][i + 1] = True
            longest_length = 2

    for length in range(3, n + 1):
        for i in range(n - length + 1):
            j = i + length - 1
            if dp[i + 1][j - 1] and s[i] == s[j]:
                dp[i][j] = True
                longest_length = length

    return longest_length