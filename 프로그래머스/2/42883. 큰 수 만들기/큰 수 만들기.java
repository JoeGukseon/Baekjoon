class Solution {
    public String solution(String number, int k) {
        int length = number.length() - k;
        char[] result = new char[length];
        int idx = 0;

        for(int i = 0; i < length; i++) {
            char max = 0;
            for(int j = idx; j <= i + k; j++) {
                if(max < number.charAt(j)) {
                    max = number.charAt(j);
                    idx = j + 1;
                }
            }
            result[i] = max;
        }

        return new String(result);
    }
}