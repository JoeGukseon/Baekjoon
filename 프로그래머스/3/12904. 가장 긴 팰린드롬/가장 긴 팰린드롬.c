#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int n = strlen(s);

    bool dp[n][n];
    
    int longestLength = 1;

    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }
    
    for (int length = 2; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1;

            dp[i][j] = (s[i] == s[j] && (length == 2 || dp[i + 1][j - 1]));
            if (dp[i][j]) {
                longestLength = length;
            }
        }
    }

    return longestLength;
}