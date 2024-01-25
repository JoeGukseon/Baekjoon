#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* word) {
    int val[] = {781, 156, 31, 6, 1};
    int answer = 0;

    for (int i = 0; word[i] != '\0'; i++) {
        int idx;
        switch (word[i]) {
            case 'A':
                idx = 0;
                break;
            case 'E':
                idx = 1;
                break;
            case 'I':
                idx = 2;
                break;
            case 'O':
                idx = 3;
                break;
            case 'U':
                idx = 4;
                break;
            default:
                idx = -1;
                break;
        }

        if (idx != -1) {
            answer += val[i] * idx;
        }
    }

    return answer + (int)strlen(word);
}