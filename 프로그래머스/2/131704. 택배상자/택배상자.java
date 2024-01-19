import java.util.*;
class Solution {
    public int solution(int[] order) {
        Stack<Integer> aux = new Stack<>();
        int idx = 1;
        int cnt = 0;
        while (idx < order.length+1) {
            aux.push(idx); 
            while (!aux.isEmpty() && aux.peek() == order[cnt]) {
                cnt++;
                aux.pop();
            }
            idx++;
        }

        return cnt;
    }
}