import java.util.*;
class Solution {
    public int[] solution(String[] operations) {
        PriorityQueue<Integer> priorityQueueMin = new PriorityQueue<>();
        PriorityQueue<Integer> priorityQueueMax = new PriorityQueue<>(Collections.reverseOrder());

        Arrays.stream(operations)
            .map(str -> str.split(" "))
            .forEach(strings ->
                     {
                         if (strings[0].equals("I")) {
                             priorityQueueMax.offer(Integer.parseInt(strings[1]));
                             priorityQueueMin.offer(Integer.parseInt(strings[1]));
                         } else if (strings[0].equals("D") && strings[1].equals("1")) {  //최대값 삭제
                             priorityQueueMin.remove(priorityQueueMax.poll());
                         } else if (strings[0].equals("D") && strings[1].equals("-1")) { //최소값 삭제
                             priorityQueueMax.remove(priorityQueueMin.poll());
                         }
                     });

        List<Integer> list1 = new ArrayList<>(priorityQueueMin);
        List<Integer> list2 = new ArrayList<>(priorityQueueMax);
        list1.retainAll(list2);

        if (list1.isEmpty()) {
            return new int[]{0,0};
        }

        list1.sort(Collections.reverseOrder());
        return new int[]{list1.get(0),list1.get(list1.size()-1)};
    }
}