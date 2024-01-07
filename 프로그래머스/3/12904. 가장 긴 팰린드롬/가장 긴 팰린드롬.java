class Solution
{
    public int solution(String s)
    {
        int longestPalindromeLength = 0;

        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                if (isPalindrome(s, i, j)) {
                    longestPalindromeLength = Math.max(longestPalindromeLength, j - i + 1);
                }
            }
        }

        return longestPalindromeLength;
    }
    
    public static boolean isPalindrome(String str, int start, int end) {
        while (start < end) {
            if (str.charAt(start) != str.charAt(end)) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
}