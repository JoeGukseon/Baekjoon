#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int dfs(int depth, int k, int** dungeons, bool* visited, size_t length) {
    int answer = 0;

    for (size_t i = 0; i < length; i++) {
        if (!visited[i] && dungeons[i][0] <= k) {
            visited[i] = true;

            int temp = dfs(depth + 1, k - dungeons[i][1], dungeons, visited, length);
            answer = (temp > answer) ? temp : answer;

            visited[i] = false;
        }
    }

    return (answer > depth) ? answer : depth;
}

// dungeons_rows는 2차원 배열 dungeons의 행 길이, dungeons_cols는 2차원 배열 dungeons의 열 길이입니다.
int solution(int k, int** dungeons, size_t dungeons_rows, size_t dungeons_cols) {
    bool* visited = (bool*)malloc(dungeons_rows * sizeof(bool));
    
    for (size_t i = 0; i < dungeons_rows; i++) {
        visited[i] = false;
    }

    int result = dfs(0, k, dungeons, visited, dungeons_rows);

    free(visited);
    return result;
}