import java.util.*;
class Solution {
    public int solution(String s) {
        int answer = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i != 0) {
                s = s.substring(1) + s.charAt(0);
            }
            answer++;
            Stack<Character> stack = new Stack<>();
            for (char ch : s.toCharArray()) {
                if (ch == '(' || ch == '[' || ch == '{') {
                    stack.push(ch);
                } else if (ch == ')' || ch == ']' || ch == '}') {
                    if (stack.isEmpty()) {
                        answer--;
                        break;
                    }
                    char top = stack.pop();
                    if ((ch == ')' && top != '(') || (ch == ']' && top != '[') || (ch == '}' && top != '{')) {
                        answer--;
                        stack.clear();
                        break;
                    }
                }
            }
            if (!stack.isEmpty()) {
                answer--;
            }
        }
        return answer;
    }
}