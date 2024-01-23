import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;

        Queue<Integer> bridge = new LinkedList<>();

        for (int i = 0; i < bridge_length; i++) {
            bridge.offer(0);
        }
        int bridge_cur_weight = 0;
        int idx = 0;


        while (!bridge.isEmpty()) {
            answer++;
            bridge_cur_weight -= bridge.poll();

            if (idx < truck_weights.length) {
                if (bridge_cur_weight + truck_weights[idx] <= weight) {
                    bridge.offer(truck_weights[idx]);
                    bridge_cur_weight += truck_weights[idx];
                    idx++;
                } else {
                    bridge.offer(0);
                }
            }
        }

        return answer;
    }
}