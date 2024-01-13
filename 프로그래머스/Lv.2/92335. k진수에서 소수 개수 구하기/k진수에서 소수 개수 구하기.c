#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <malloc.h>

bool is_prime(long long n) {
    if (n <= 1) return false;
    else if (n == 2) return true;

    for (long long i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }

    return true;
}

char* to_knum(int n, int k) {
    int length = 0;
    int temp = n;

    while (temp > 0) {
        temp /= k;
        length++;
    }

    char* result = (char*)malloc((length + 1) * sizeof(char));

    int index = 0;
    while (n > 0) {
        result[length - 1 - index++] = n % k + '0';
        n /= k;
    }

    result[index] = '\0';

    return result;
}

char* substring(char* str, int start, int end) {
    int length = end - start;
    char* result = (char*)malloc(length + 1); 
    
    for (int i = 0; i < length; i++) {
        result[i] = str[start + i];
    }

    result[length] = '\0';

    return result;
}

int solution(int n, int k) {
    int answer = 0;
    char* s = to_knum(n, k);
    
    for (int i = 0, j; s[i] != '\0'; i = j) {
        for (j = i + 1; s[j] != '\0' && s[j] != '0'; j++);

        char* substring_result = substring(s, i, j);

        char* endptr;
        long long number = strtoll(substring_result, &endptr, 10);

        free(substring_result);

        if (is_prime(number)) {
            answer++;
        }
    }

    free(s);

    return answer;
}
