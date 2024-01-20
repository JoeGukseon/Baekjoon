#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// arrayA_len은 배열 arrayA의 길이입니다.
// arrayB_len은 배열 arrayB의 길이입니다.
int solution(int arrayA[], size_t arrayA_len, int arrayB[], size_t arrayB_len) {
    int gcdA = arrayA[0];
    int gcdB = arrayB[0];

    for (size_t i = 1; i < arrayA_len; i++) {
        gcdA = gcd(arrayA[i], gcdA);
    }

    for (size_t i = 1; i < arrayB_len; i++) {
        gcdB = gcd(arrayB[i], gcdB);
    }

    for (size_t i = 0; i < arrayB_len; i++) {
        if (arrayB[i] % gcdA == 0) {
            gcdA = 0;
            break;
        }
    }

    for (size_t i = 0; i < arrayA_len; i++) {
        if (arrayA[i] % gcdB == 0) {
            gcdB = 0;
            break;
        }
    }

    return (gcdA > gcdB) ? gcdA : gcdB;
}