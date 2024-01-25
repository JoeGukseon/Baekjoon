class Solution {
    public int solution(String word) {
        int[] val = {781, 156, 31, 6, 1};
        int answer = word.length();

        for (int i = 0; i < word.length(); i++) {
            int idx;
            switch (word.charAt(i)) {
                case 'A':
                    idx = 0;
                    break;
                case 'E':
                    idx = 1;
                    break;
                case 'I':
                    idx = 2;
                    break;
                case 'O':
                    idx = 3;
                    break;
                case 'U':
                    idx = 4;
                    break;
                default:
                    idx = -1;
                    break;
            }
            if (idx != -1) {
                answer += val[i] * idx;
            }
        }

        return answer;
    }
}