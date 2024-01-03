#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
bool solution(const char* s) {
    char stack[strlen(s)];
    size_t top = 0;

    for (size_t i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            stack[top++] = s[i];
        } else {
            if (top > 0) {
                top--;
            } else {
                return false;
            }
        }
    }

    return top == 0;
}