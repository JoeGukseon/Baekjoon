#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int gCol;

int compare(const void *a, const void *b) {
    const int *tuple1 = *(const int **)a;
    const int *tuple2 = *(const int **)b;

    if (tuple1[gCol-1] != tuple2[gCol-1]) {
        return tuple1[gCol-1] - tuple2[gCol-1];
    }

    return tuple2[0] - tuple1[0];
}

// data_rows는 2차원 배열 data의 행 길이, data_cols는 2차원 배열 data의 열 길이입니다.
int solution(int** data, size_t data_rows, size_t data_cols, int col, int row_begin, int row_end) {
    gCol = col;
    qsort(data, data_rows, sizeof(int *), compare);

    int hash_value = 0;

    for (int i = row_begin - 1; i < row_end; i++) {
        int si = 0;
        for (size_t j = 0; j < data_cols; j++) {
            si += data[i][j] % (i+1);
        }
        hash_value ^= si;
    }

    return hash_value;
}