class Solution
{
    public int solution(String s)
    {
        int n = s.length();

        boolean[][] dp = new boolean[n][n];

        int longestLength = 1;

        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        for (int length = 2; length <= n; length++) {
            for (int i = 0; i <= n - length; i++) {
                int j = i + length - 1;
                if (s.charAt(i) == s.charAt(j)) {
                    if (length == 2 || dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                        longestLength = length;
                    }
                }
            }
        }

        return longestLength;
    }
}