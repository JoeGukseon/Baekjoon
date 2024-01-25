import java.util.Arrays;
class Solution {
    public String solution(int[] numbers) {
        boolean zero = Arrays.stream(numbers).allMatch(n -> n == 0);
        if (zero) {
            return "0";
        }
        String[] arrStr = Arrays.stream(numbers)
                .mapToObj(String::valueOf)
                .toArray(String[]::new);
        Arrays.sort(arrStr, (a, b) -> (b + a).compareTo(a + b));

        return String.join("",arrStr);
    }
}