import java.util.*;

class Solution {
    public int solution(int[] queue1, int[] queue2) {
        Queue<Integer> currentQ1 = new LinkedList<>();
        Queue<Integer> currentQ2 = new LinkedList<>();
        
        long sumQ1 = 0;
        long sumQ2 = 0;
        
        for (int num : queue1) {
            currentQ1.offer(num);
            sumQ1 += num;
        }
        for (int num : queue2) {
            currentQ2.offer(num);
            sumQ2 += num;
        }
        
        int answer = -1;
        long totalSum = sumQ1 + sumQ2;
        long targetSum = totalSum / 2;

        if (totalSum % 2 != 0) {
            return -1;
        }
        
        long currentSum = sumQ1;

        int operationsCount = 0;

        if (max(currentQ1) > targetSum || max(currentQ2) > targetSum) {
            return -1;
        }

        while (!currentQ1.isEmpty() && !currentQ2.isEmpty()) {
            if (currentSum > targetSum) {
                currentSum -= currentQ1.poll();
                operationsCount++;
            } else if (currentSum < targetSum) {
                int element = currentQ2.poll();
                currentQ1.offer(element);
                currentSum += element;
                operationsCount++;
            } else if (currentSum == targetSum) {
                return operationsCount;
            }
        }

        return -1;
    }

    private static int max(Queue<Integer> queue) {
        int max = Integer.MIN_VALUE;
        for (int num : queue) {
            max = Math.max(max, num);
        }
        return max;
    }
}