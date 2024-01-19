#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// order_len은 배열 order의 길이입니다.
int solution(int order[], size_t order_len) {
    int answer = 0;
    int stack[order_len];
    int top = -1;

    for (int i = 1; i <= order_len; i++) {
        stack[++top] = i;

        while (top >= 0 && stack[top] == order[answer]) {
            top--;
            answer++;
        }
    }

    return answer;
}