class Solution {
    public int solution(int k, int[][] dungeons) {
        boolean[] visited = new boolean[dungeons.length];

        return dfs(0, k, dungeons, visited);
    }

    private int dfs(int depth, int k, int[][] dungeons, boolean[] visited) {
        int answer=0;
        for (int i = 0; i < dungeons.length; i++) {

            if (!visited[i] && dungeons[i][0] <= k) {
                visited[i] = true;

                answer = Math.max(answer, dfs(depth + 1, k - dungeons[i][1], dungeons, visited));

                visited[i] = false;
            }

        }
        return Math.max(answer, depth);
    }
}