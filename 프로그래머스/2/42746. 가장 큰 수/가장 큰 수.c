#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    char str1[9], str2[9];
    sprintf(str1, "%d%d", *(int*)b, *(int*)a);
    sprintf(str2, "%d%d", *(int*)a, *(int*)b);
    return strcmp(str1, str2);
}

// numbers_len은 배열 numbers의 길이입니다.
char* solution(int numbers[], size_t numbers_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int isAllZero = 1;
    for (int i = 0; i < numbers_len; ++i) {
        if (numbers[i] != 0) {
            isAllZero = 0;
            break;
        }
    }
    
    if (isAllZero) {
        return "0";
    }
    
    qsort(numbers, numbers_len, sizeof(int), compare);
    
    char* answer = (char*)malloc(20 * numbers_len);
    answer[0] = '\0';

    for (size_t i = 0; i < numbers_len; ++i) {
        char numStr[5];
        sprintf(numStr, "%d", numbers[i]);
        strcat(answer, numStr);
    }
    
    return answer;
}