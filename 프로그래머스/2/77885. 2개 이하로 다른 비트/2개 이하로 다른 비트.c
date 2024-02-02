#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long powerOfTwo(int exponent) {
    long long result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= 2;
    }
    return result;
}

// numbers_len은 배열 numbers의 길이입니다.
long long* solution(long long numbers[], size_t numbers_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    long long* answer = (long long*)malloc(numbers_len * sizeof(long long));
    
    for (size_t i = 0; i < numbers_len; i++) {
        if (numbers[i] % 2 == 0) {
            answer[i] = numbers[i] + 1;
        } else {
            long long bit = 1;
            while (1) {
                if ((numbers[i] & bit) == 0) break;
                bit *= 2;
            }
            bit = bit / 2;
            answer[i] = numbers[i] + bit;
        }
    }

    return answer;
}