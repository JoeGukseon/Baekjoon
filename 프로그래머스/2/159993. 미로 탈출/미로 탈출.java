import java.util.*;

class Solution {
    public int solution(String[] maps) {
        int rows = maps.length;
        int cols = maps[0].length();

        Pair start = null, lever = null, end = null;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                char current = maps[i].charAt(j);

                if (current == 'S') {
                    start = new Pair(i, j);
                } else if (current == 'L') {
                    lever = new Pair(i, j);
                } else if (current == 'E') {
                    end = new Pair(i, j);
                }
            }
        }

        int leverDistance = bfs(maps, start, lever);

        if (leverDistance == -1) {
            return -1;
        }

        int exitDistance = bfs(maps, lever, end);

        if (exitDistance == -1) {
            return -1;
        }

        return leverDistance + exitDistance;
    }
    
    private int bfs(String[] maps, Pair start, Pair target) {
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};

        int rows = maps.length;
        int cols = maps[0].length();

        Set<Pair> visited = new HashSet<>();
        Queue<PairWithTime> queue = new ArrayDeque<>();

        queue.add(new PairWithTime(start, 0));
        visited.add(start);

        while (!queue.isEmpty()) {
            PairWithTime current = queue.poll();

            if (current.pair.equals(target)) {
                return current.time;
            }

            for (int d = 0; d < 4; d++) {
                int ni = current.pair.i + dx[d];
                int nj = current.pair.j + dy[d];

                if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && maps[ni].charAt(nj) != 'X' && !visited.contains(new Pair(ni, nj))) {
                    visited.add(new Pair(ni, nj));
                    queue.add(new PairWithTime(new Pair(ni, nj), current.time + 1));
                }
            }
        }

        return -1;
    }
    
    class Pair {
        int i, j;

        public Pair(int i, int j) {
            this.i = i;
            this.j = j;
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj) return true;
            if (obj == null || getClass() != obj.getClass()) return false;
            Pair pair = (Pair) obj;
            return i == pair.i && j == pair.j;
        }
        
        @Override
        public int hashCode() {
            return Objects.hash(i, j);
        }
    }
    
    class PairWithTime {
        Pair pair;
        int time;

        public PairWithTime(Pair pair, int time) {
            this.pair = pair;
            this.time = time;
        }
    }
}