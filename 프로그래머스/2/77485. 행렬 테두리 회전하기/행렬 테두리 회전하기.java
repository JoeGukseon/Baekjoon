class Solution {
    public int[] solution(int rows, int columns, int[][] queries) {
        int[][] matrix = new int[rows][columns];
        int[] answer = new int[queries.length];
        int count = 1;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                matrix[i][j] = count++;
            }
        }
        
        for (int i = 0; i < queries.length; i++) {
            answer[i] = rotate(matrix, queries[i][0], queries[i][1], queries[i][2], queries[i][3]);
        }
        
        return answer;
    }
    
    public static int rotate(int[][] matrix, int x1, int y1, int x2, int y2) {
        int temp = matrix[x1 - 1][y1 - 1];
        int minVal = temp;

        for (int i = y1; i < y2; i++) {
            int current = matrix[x1 - 1][i];
            matrix[x1 - 1][i] = temp;
            temp = current;
            minVal = Math.min(minVal, temp);
        }

        for (int i = x1; i < x2; i++) {
            int current = matrix[i][y2 - 1];
            matrix[i][y2 - 1] = temp;
            temp = current;
            minVal = Math.min(minVal, temp);
        }

        for (int i = y2 - 2; i >= y1 - 1; i--) {
            int current = matrix[x2 - 1][i];
            matrix[x2 - 1][i] = temp;
            temp = current;
            minVal = Math.min(minVal, temp);
        }

        for (int i = x2 - 2; i >= x1 - 1; i--) {
            int current = matrix[i][y1 - 1];
            matrix[i][y1 - 1] = temp;
            temp = current;
            minVal = Math.min(minVal, temp);
        }

        return minVal;
    }
    
}