import java.util.*;

class Solution {
    public long solution(int[] weights) {
    	// 무게를 저장하는 Map
        Map<Double, Integer> weightOccurrences = new HashMap<>();

        // 시소 짝꿍의 총 개수를 저장할 변수
        long totalCouples = 0;

        // 무게 배열을 오름차순으로 정렬
        Arrays.sort(weights);

        // 무게 배열을 순회하며 시소 짝꿍 찾기
        for (int currentWeight : weights) {
            // 현재 무게에서의 토크 값들 계산
            double weightA = currentWeight * 1.0;   // 1
            double weightB = (currentWeight * 2.0) / 3.0;   // 2/3
            double weightC = (currentWeight * 1.0) / 2.0;   // 1/2
            double weightD = (currentWeight * 3.0) / 4.0;   // 3/4

            // 이미 나온 토크 값들이 저장된 Map에서 해당 토크가 나온 횟수를 가져와 누적
            totalCouples += weightOccurrences.getOrDefault(weightA, 0);
            totalCouples += weightOccurrences.getOrDefault(weightB, 0);
            totalCouples += weightOccurrences.getOrDefault(weightC, 0);
            totalCouples += weightOccurrences.getOrDefault(weightD, 0);

            // 현재 무게의 토크 값을 Map에 추가하고 등장 횟수를 1 증가
            weightOccurrences.put(weightA, weightOccurrences.getOrDefault(weightA, 0) + 1);
        }

        // 최종적으로 계산된 시소 짝꿍의 개수 반환
        return totalCouples;
        
    }
}