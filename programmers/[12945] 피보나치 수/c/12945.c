#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    if (n <= 1)
        return n;

    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % 1234567;
    }

    return fib[n];
}