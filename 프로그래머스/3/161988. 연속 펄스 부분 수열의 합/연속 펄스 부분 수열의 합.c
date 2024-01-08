#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// sequence_len은 배열 sequence의 길이입니다.
long long solution(int sequence[], size_t sequence_len) {
    long long answer = 0;
    int is_plus = 1;
    long purse1 = 0, purse2 = 0;
    
     for (int i = 0; i < sequence_len; i++) {
        if (is_plus) {
            purse1 += sequence[i];
            purse2 += -sequence[i];
        } else {
            purse1 += -sequence[i];
            purse2 += sequence[i];
        }

        purse1 = purse1 > 0 ? purse1 : 0;
        purse2 = purse2 > 0 ? purse2 : 0;

        answer = answer > purse1 ? answer : purse1;
        answer = answer > purse2 ? answer : purse2;

        is_plus = !is_plus;
    }

    return answer;
}