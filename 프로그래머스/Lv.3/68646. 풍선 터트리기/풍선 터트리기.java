class Solution {
    public int solution(int[] a) {
        int n = a.length;
        if (n == 1) return 1;  // 원소가 1이면 답은 1

        int[] leftMin = new int[n];  // 각 인덱스에서 왼쪽의 최소값을 저장하는 배열
        int minToLeft = a[0]; // 왼쪽 최소값 초기화

        int[] rightMin = new int[n]; // 각 인덱스에서 오른쪽의 최소값을 저장하는 배열
        int minToRight = a[n - 1]; // 오른쪽 최소값 초기화

        // 왼쪽과 오른쪽 최소값 계산
        for (int i = 1; i < n - 1; i++) {
            if (minToLeft > a[i]) minToLeft = a[i];
            leftMin[i] = minToLeft;

            if (minToRight > a[n - 1 - i]) minToRight = a[n - 1 - i];
            rightMin[n - 1 - i] = minToRight;
        }

        int answer = 2; // 반환할 값. 원소가 2개 이상인 경우 무조건 2개 이상

        // 풍선 터트리기
        for (int i = 1; i <= n - 2; i++) {
            //현재 풍선의 값이 그 양옆의 풍선보다 크다면 터트리지 않는다.
            if (a[i] > leftMin[i] && a[i] > rightMin[i]) continue;
            answer++;
        }

        return answer;
    }
}