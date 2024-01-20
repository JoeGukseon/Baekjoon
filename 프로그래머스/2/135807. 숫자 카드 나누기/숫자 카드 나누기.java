class Solution {
    public int solution(int[] arrayA, int[] arrayB) {
        int gcdA = arrayA[0];
        int gcdB = arrayB[0];

        for (int i = 1; i < arrayA.length; i++) {
            gcdA = calculateGCD(arrayA[i], gcdA);
        }

        for (int i = 1; i < arrayB.length; i++) {
            gcdB = calculateGCD(arrayB[i], gcdB);
        }

        for (int num : arrayB) {
            if (num % gcdA == 0) {
                gcdA = 0;
                break;
            }
        }

        for (int num : arrayA) {
            if (num % gcdB == 0) {
                gcdB = 0;
                break;
            }
        }

        return Math.max(gcdA, gcdB);
    }

    
    private static int calculateGCD(int a, int b) {
        if (b == 0) {
            return a;
        }
        return calculateGCD(b, a % b);
    }
}