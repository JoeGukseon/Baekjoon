#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Point {
    int x, y;
};

// board_len은 배열 board의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* board[], size_t board_len) {
    int cur_x = 0, cur_y = 0;

    for (int i = 0; i < board_len; i++) {
        for (int j = 0; j < strlen(board[i]); j++) {
            if (board[i][j] == 'R') {
                cur_x = i;
                cur_y = j;
            }
        }
    }

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    struct Point queue[MAX_SIZE * MAX_SIZE];
    size_t front = 0, rear = 0;

    queue[rear].x = cur_x;
    queue[rear].y = cur_y;
    rear++;

    int visited[MAX_SIZE][MAX_SIZE];
    memset(visited, 0, sizeof(visited));
    visited[cur_x][cur_y] = 1;

    while (front != rear) {
        struct Point pos = queue[front++];
        int cx = pos.x;
        int cy = pos.y;

        if (board[cx][cy] == 'G') {
            return visited[cx][cy] - 1;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cx;
            int ny = cy;
            while (1) {
                nx += dx[i];
                ny += dy[i];

                if (nx < 0 || nx >= board_len || ny < 0 || ny >= strlen(board[nx]) || board[nx][ny] == 'D') {
                    nx -= dx[i];
                    ny -= dy[i];
                    break;
                }
            }

            if (visited[nx][ny] == 0) {
                visited[nx][ny] = visited[cx][cy] + 1;
                queue[rear].x = nx;
                queue[rear].y = ny;
                rear++;
            }
        }
    }

    return -1;
}