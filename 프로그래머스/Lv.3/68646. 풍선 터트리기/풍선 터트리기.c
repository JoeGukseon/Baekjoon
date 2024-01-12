#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// a_len은 배열 a의 길이입니다.
int solution(int a[], size_t a_len) {
    int n = a_len;
    if (n == 1) return 1;

    int leftMin[n];
    int minToLeft = a[0];

    int rightMin[n];
    int minToRight = a[n - 1];

    for (int i = 1; i < n - 1; i++) {
        if (minToLeft > a[i]) minToLeft = a[i];
        leftMin[i] = minToLeft;

        if (minToRight > a[n - 1 - i]) minToRight = a[n - 1 - i];
        rightMin[n - 1 - i] = minToRight;
    }

    int answer = 2;

    for (int i = 1; i <= n - 2; i++) {
        if (a[i] > leftMin[i] && a[i] > rightMin[i]) continue;
        answer++;
    }

    return answer;
}