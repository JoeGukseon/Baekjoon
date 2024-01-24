import java.util.Stack;
class Solution {
    public int[] solution(int[] numbers) {
        int[] answer = new int[numbers.length];
        Stack<Integer> stack = new Stack<>();

        for (int i = numbers.length - 1; i >= 0; i--) {
            while (!stack.isEmpty() && numbers[stack.peek()] <= numbers[i]) {
                stack.pop();
            }
            if (stack.isEmpty()) {
                answer[i] = -1;
            } else {
                answer[i] = numbers[stack.peek()];
            }
            stack.push(i);
        }

        return answer;
    }
}