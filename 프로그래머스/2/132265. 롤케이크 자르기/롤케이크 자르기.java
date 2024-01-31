import java.util.*;
class Solution {
    public int solution(int[] topping) {
        int answer = 0;
        Map<Integer, Integer> countMap = new HashMap<>();
        Set<Integer> set = new HashSet<>();

        for (int i : topping) {
            countMap.put(i, countMap.getOrDefault(i, 0) + 1);
        }

        for (int i : topping) {
            countMap.put(i, countMap.get(i) - 1);
            set.add(i);
            if (countMap.get(i) == 0) {
                countMap.remove(i);
            }
            if (countMap.size() == set.size()) {
                answer++;
            }
        }

        return answer;
    }
}