import java.util.*;

class Solution {
    public int solution(String[] board) {
        int result = 0;
        int R = board.length;
        int C = board[0].length();
        int cur_x = 0, cur_y = 0;

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (board[i].charAt(j) == 'R') {
                    cur_x = i;
                    cur_y = j;
                }
            }
        }

        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};

        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{cur_x, cur_y});
        int[][] visited = new int[R][C];
        visited[cur_x][cur_y] = 1;

        while (!queue.isEmpty()) {
            int[] pos = queue.poll();
            int cx = pos[0];
            int cy = pos[1];

            if (board[cx].charAt(cy) == 'G') {
                return visited[cx][cy] - 1;
            }

            for (int i = 0; i < 4; i++) {
                int nx = cx;
                int ny = cy;
                while (true) {
                    nx += dx[i];
                    ny += dy[i];

                    if (nx < 0 || nx >= R || ny < 0 || ny >= C || board[nx].charAt(ny) == 'D') {
                        nx -= dx[i];
                        ny -= dy[i];
                        break;
                    }
                }

                if (visited[nx][ny] == 0) {
                    visited[nx][ny] = visited[cx][cy] + 1;
                    queue.offer(new int[]{nx, ny});
                }
            }
        }

        return -1;
    }
}