#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 0;
    int length = strlen(s);

    char* rotatedString = (char*)malloc((length + 1) * sizeof(char));
    strcpy(rotatedString, s);

    for (int i = 0; i < length; i++) {
        if (i != 0) {
            char firstChar = rotatedString[0];
            memmove((void*)rotatedString, (void*)(rotatedString + 1), length - 1);
            rotatedString[length - 1] = firstChar;
        }

        answer++;
        char stack[length];
        int top = -1;

        for (int j = 0; j < length; j++) {
            char ch = rotatedString[j];
            if (ch == '(' || ch == '[' || ch == '{') {
                stack[++top] = ch;
            } else if (ch == ')' || ch == ']' || ch == '}') {
                if (top == -1) {
                    answer--;
                    break;
                }
                char stackTop = stack[top--];
                if ((ch == ')' && stackTop != '(') || (ch == ']' && stackTop != '[') || (ch == '}' && stackTop != '{')) {
                    answer--;
                    top = -1;
                    break;
                }
            }
        }

        if (top != -1) {
            answer--;
        }
    }

    free(rotatedString);
    return answer;
}