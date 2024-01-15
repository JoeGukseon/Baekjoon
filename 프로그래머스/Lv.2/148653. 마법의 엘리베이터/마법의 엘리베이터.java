class Solution {
    public int solution(int storey) {
        int totalMagicStones = 0;

        while (storey != 0) {
            int lastDigit = storey % 10;

            if (lastDigit > 5) {
                totalMagicStones += (10 - lastDigit);
                storey += 10;
            }
            else if (lastDigit < 5) {
                totalMagicStones += lastDigit;
            }
            else {
                int nextDigit = (storey / 10) % 10;
                if (nextDigit > 4) {
                    storey += 10;
                }
                totalMagicStones += lastDigit;
            }

            storey /= 10;
        }

        return totalMagicStones;
    }
}