#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* number, int k) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int length = strlen(number) - k;
    char* result = (char*)malloc((length + 1) * sizeof(char));
    int idx = 0;

    for (int i = 0; i < length; ++i) {
        char max_char = '0';
        for (int j = idx; j <= i + k; ++j) {
            if (max_char < number[j]) {
                max_char = number[j];
                idx = j + 1;
            }
        }
        result[i] = max_char;
    }
    result[length] = '\0';

    return result;
}