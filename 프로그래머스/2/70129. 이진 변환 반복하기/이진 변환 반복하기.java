class Solution {
    public int[] solution(String s) {
        int[] answer = new int[2];

        int cnt = 0;
        int zCnt = 0;

        while (!s.equals("1")) {
            cnt++;
            zCnt += (int) s.chars()
                    .filter(c -> c != '1')
                    .count();
            System.out.println("zCnt = " + zCnt);
            s = s.replace("0", "");
            s = Integer.toBinaryString(s.length());
            System.out.println("s = " + s);
        }

        answer[0] = cnt;
        answer[1] = zCnt;
        return answer;
    }
}