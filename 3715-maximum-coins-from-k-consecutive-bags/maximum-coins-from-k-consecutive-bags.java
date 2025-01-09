class Solution {
    public long maximumCoins(int[][] coins, int k) {
        Arrays.sort(coins, (a, b) -> a[0] - b[0]);
        int n = coins.length;
        long result = 0, currentSum = 0;

        // Case 1: The chosen k-length segment starts at coins[i][0]
        for (int i = 0, j = 0; i < n; i++) {

            while (j < n && coins[j][1] <= coins[i][0] + k - 1) {
                currentSum += (long) (coins[j][1] - coins[j][0] + 1) * coins[j][2];
                j++;
            }

            if (j < n) {
                long partial = (long) Math.max(0, coins[i][0] + k - 1 - coins[j][0] + 1) * coins[j][2];
                result = Math.max(result, currentSum + partial);
            }

            currentSum -= (long) (coins[i][1] - coins[i][0] + 1) * coins[i][2];
        }

        // Case 2: The chosen k-length segment ends at coins[i][1]
        currentSum = 0;
        for (int i = 0, j = 0; i < n; i++) {
            currentSum += (long) (coins[i][1] - coins[i][0] + 1) * coins[i][2];

            while (coins[j][1] < coins[i][1] - k + 1) {
                currentSum -= (long) (coins[j][1] - coins[j][0] + 1) * coins[j][2];
                j++;
            }

            long partial = (long) Math.max(0, coins[i][1] - k - coins[j][0] + 1) * coins[j][2];
            result = Math.max(result, currentSum - partial);
        }

        return result;
    }
}