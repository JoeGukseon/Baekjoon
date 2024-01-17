#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int rotate(int** matrix, int x1, int y1, int x2, int y2) {
    int temp = matrix[x1 - 1][y1 - 1];
    int min_val = temp;

    for (int i = y1; i < y2; i++) {
        int temp_val = matrix[x1 - 1][i];
        matrix[x1 - 1][i] = temp;
        temp = temp_val;
        min_val = (min_val < temp) ? min_val : temp;
    }

    for (int i = x1; i < x2; i++) {
        int temp_val = matrix[i][y2 - 1];
        matrix[i][y2 - 1] = temp;
        temp = temp_val;
        min_val = (min_val < temp) ? min_val : temp;
    }

    for (int i = y2 - 2; i >= y1 - 1; i--) {
        int temp_val = matrix[x2 - 1][i];
        matrix[x2 - 1][i] = temp;
        temp = temp_val;
        min_val = (min_val < temp) ? min_val : temp;
    }

    for (int i = x2 - 2; i >= x1 - 1; i--) {
        int temp_val = matrix[i][y1 - 1];
        matrix[i][y1 - 1] = temp;
        temp = temp_val;
        min_val = (min_val < temp) ? min_val : temp;
    }

    return min_val;
}

// queries_row_len은 2차원 배열 queries의 행(세로) 길이입니다.
// queries_col_len은 2차원 배열 queries의 열(가로) 길이입니다.
// queries[i][j]는 queries의 i번째 행의 j번째 열에 저장된 값을 의미합니다.
int* solution(int rows, int columns, int **queries, size_t queries_row_len, size_t queries_col_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요
    int** matrix = (int**)malloc(rows * sizeof(int*));
    
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(columns * sizeof(int));
    }
    
    int count = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = count++;
        }
    }
    
    int* answer = (int*)malloc(queries_row_len * sizeof(int));
    
    for (size_t i = 0; i < queries_row_len; i++) {
        answer[i] = rotate(matrix, queries[i][0], queries[i][1], queries[i][2], queries[i][3]);
    }
    
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    
    return answer;
}