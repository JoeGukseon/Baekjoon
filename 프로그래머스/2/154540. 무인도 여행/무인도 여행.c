#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

int isValid(int x, int y, int rows, int cols, const char* map[MAX_ROWS], int visited[MAX_ROWS][MAX_COLS]) {
    return (x >= 0 && x < cols && y >= 0 && y < rows && !visited[y][x] && map[y][x] != 'X');
}

void bfs(int start_x, int start_y, int rows, int cols, const char* map[MAX_ROWS], int visited[MAX_ROWS][MAX_COLS], int* sum) {
    int queue[MAX_ROWS * MAX_COLS][2];
    int front = -1, rear = -1;

    queue[++rear][0] = start_x;
    queue[rear][1] = start_y;
    visited[start_y][start_x] = 1;

    while (front != rear) {
        int curX = queue[++front][0];
        int curY = queue[front][1];

        *sum += map[curY][curX] - '0';

        for (int k = 0; k < 4; k++) {
            int newX = curX + directions[k][0];
            int newY = curY + directions[k][1];

            if (isValid(newX, newY, rows, cols, map, visited)) {
                queue[++rear][0] = newX;
                queue[rear][1] = newY;
                visited[newY][newX] = 1;
            }
        }
    }
}

// maps_len은 배열 maps의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* maps[], size_t maps_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int visited[MAX_ROWS][MAX_COLS] = {{0}};
    int* result = (int*)malloc(MAX_ROWS * MAX_COLS * sizeof(int));
    int resultIndex = 0;

    for (size_t y = 0; y < maps_len; y++) {
        size_t cols = strlen(maps[y]);
        for (size_t x = 0; x < cols; x++) {
            if (!visited[y][x] && maps[y][x] != 'X') {
                int sum = 0;
                bfs(x, y, maps_len, cols, maps, visited, &sum);
                result[resultIndex++] = sum;
            }
        }
    }

    if (resultIndex == 0) {
        result[0] = -1;
        return result;
    }

    for (int i = 0; i < resultIndex - 1; i++) {
        for (int j = i + 1; j < resultIndex; j++) {
            if (result[i] > result[j]) {
                int temp = result[i];
                result[i] = result[j];
                result[j] = temp;
            }
        }
    }

    return result;
}