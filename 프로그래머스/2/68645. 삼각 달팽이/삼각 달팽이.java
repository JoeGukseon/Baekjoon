class Solution {
    public int[] solution(int n) {
        int[][] arr = new int[n][n];

        int num = 1;
        int row = -1;
        int col = 0;

        arr[row+1][col] = num;

        for (int i = n; i > 0; i -= 3) {
            for (int j = 0; j < i; j++) {
                arr[++row][col] = num++;
            }
            for (int j = 0; j < i - 1; j++) {
                arr[row][++col] = num++;
            }
            for (int j = 0; j < i - 2; j++) {
                arr[--row][--col] = num++;
            }
        }

        int[] answer = new int[num - 1];
        int idx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] != 0) {
                    answer[idx++] = arr[i][j];
                }
            }
        }

        return answer;
    }
}