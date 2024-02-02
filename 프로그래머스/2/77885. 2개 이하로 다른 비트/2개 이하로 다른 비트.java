class Solution {
    public long[] solution(long[] numbers) {
        long[] answer = new long[numbers.length];
        for (int i = 0; i < numbers.length; i++) {
            if (numbers[i] % 2 == 0) {
                answer[i] = numbers[i] + 1;
            } else {
                StringBuilder binary = new StringBuilder(Long.toBinaryString(numbers[i]));
                int lastIndexOf01 = binary.lastIndexOf("01");
                if (lastIndexOf01 >= 0) {
                    binary.setCharAt(lastIndexOf01, '1');
                    binary.setCharAt(lastIndexOf01 + 1, '0');
                } else { //"01"이 없는경우
                    binary.deleteCharAt(0);
                    binary.insert(0, "10");
                }
                answer[i] = Long.valueOf(binary.toString(), 2);
            }
        }
        return answer;
    }
}