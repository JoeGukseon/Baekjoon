#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int** arr = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        arr[i] = (int*)calloc(n, sizeof(int));
    }

    int num = 1;
    int row = -1;
    int col = 0;

    arr[row + 1][col] = num;

    for (int i = n; i > 0; i -= 3) {
        for (int j = 0; j < i; j++) {
            row++;
            arr[row][col] = num++;
        }
        for (int j = 0; j < i - 1; j++) {
            col++;
            arr[row][col] = num++;
        }
        for (int j = 0; j < i - 2; j++) {
            row--;
            col--;
            arr[row][col] = num++;
        }
    }

    int* answer = (int*)malloc((num - 1) * sizeof(int));
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] != 0) {
                answer[idx++] = arr[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);

    return answer;
}