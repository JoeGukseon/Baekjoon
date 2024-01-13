import java.util.Arrays;

class Solution {
    private boolean isPrime(long n) {
        if (n <= 1) return false;
        else if (n == 2) return true;
        for (int i = 2; i <= Math.sqrt(n); i++)
            if (n % i == 0)
                return false;
        return true;
    }

    public class KnumConverter {
        public boolean isPrime(long n) {
            if (n <= 1) return false;
            for (int i = 2; i * i <= n; i++)
                if (n % i == 0)
                    return false;
            return true;
        }

        public String toKnum(int n, int k) {
            return Integer.toString(n, k);
        }
    }

    
    public int solution(int n, int k) {
        int answer = 0;
        StringBuilder sb = new StringBuilder();
        
        while (n > 0) {
            sb.insert(0, n % k);
            n /= k;
        }
        String s = sb.toString();

        for(int i = 0, j; i < s.length(); i = j) {
            for(j = i + 1; j < s.length() && s.charAt(j) != '0'; j++);
            if(isPrime(Long.parseLong(s.substring(i,j))))
                answer++;
        }
        return answer;
    }
}