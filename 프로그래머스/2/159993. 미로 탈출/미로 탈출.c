#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int i, j;
} Pair;

typedef struct {
    Pair pair;
    int time;
} PairWithTime;

int bfs(char** maps, int rows, int cols, Pair start, Pair target) {
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    bool** visited = (bool**)malloc(rows * sizeof(bool*));
    for (int i = 0; i < rows; i++) {
        visited[i] = (bool*)malloc(cols * sizeof(bool));
        for (int j = 0; j < cols; j++) {
            visited[i][j] = false;
        }
    }

    PairWithTime* queue = (PairWithTime*)malloc(rows * cols * sizeof(PairWithTime));
    int front = 0, rear = 0;
    queue[rear++] = (PairWithTime){start, 0};
    visited[start.i][start.j] = true;

    while (front < rear) {
        PairWithTime current = queue[front++];

        if (current.pair.i == target.i && current.pair.j == target.j) {
            for (int i = 0; i < rows; i++) {
                free(visited[i]);
            }
            free(visited);
            free(queue);

            return current.time;
        }

        for (int d = 0; d < 4; d++) {
            int ni = current.pair.i + dx[d];
            int nj = current.pair.j + dy[d];

            if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && maps[ni][nj] != 'X' && !visited[ni][nj]) {
                queue[rear++] = (PairWithTime){{ni, nj}, current.time + 1};
                visited[ni][nj] = true;
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        free(visited[i]);
    }
    free(visited);
    free(queue);

    return -1;
}

// maps_len은 배열 maps의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* maps[], size_t maps_len) {
    Pair start = {0, 0}, lever = {0, 0}, exit = {0, 0};
    int rows = maps_len;
    int cols = strlen(maps[0]);
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            char current = maps[i][j];

            if (current == 'S') {
                start = (Pair){i, j};
            } else if (current == 'L') {
                lever = (Pair){i, j};
            } else if (current == 'E') {
                exit = (Pair){i, j};
            }
        }
    }

    int leverDistance = bfs(maps, rows, cols, start, lever);

    if (leverDistance == -1) {
        return -1;
    }

    int exitDistance = bfs(maps, rows, cols, lever, exit);

    if (exitDistance == -1) {
        return -1;
    }

    return leverDistance + exitDistance;
}