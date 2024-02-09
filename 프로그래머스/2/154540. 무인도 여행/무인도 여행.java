import java.util.*;
class Solution {
    public int[] solution(String[] maps) {
        int[][] dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        boolean[][] visited = new boolean[maps.length][maps[0].length()];
        List<Integer> answer = new ArrayList<>();

        char[][] map = Arrays.stream(maps).map(String::toCharArray).toArray(char[][]::new);

        for (int y = 0; y < maps.length; y++) { //세로
            for (int x = 0; x < maps[y].length(); x++) { //가로
                if (!visited[y][x] && maps[y].charAt(x) != 'X') {
                    Queue<int[]> queue = new LinkedList<>();
                    queue.add(new int[]{x, y});
                    visited[y][x] = true;
                    int sum = 0;
                    while (!queue.isEmpty()) {
                        int[] pos = queue.poll();
                        int curX = pos[0];
                        int curY = pos[1];

                        sum += map[curY][curX] - '0';
                        for (int k = 0; k < dir.length; k++) {
                            int nx = curX + dir[k][0];
                            int ny = curY + dir[k][1];

                            if (ny >= 0 && ny < map.length && nx >= 0 && nx < map[0].length && !visited[ny][nx] && map[ny][nx] != 'X') {
                                queue.add(new int[]{nx, ny});
                                visited[ny][nx] = true;
                            }
                        }
                    }
                    answer.add(sum);
                }
            }
        }
        if (answer.isEmpty()) {
            return new int[]{-1};
        }
        return answer.stream().sorted().mapToInt(Integer::intValue).toArray();
    }
}