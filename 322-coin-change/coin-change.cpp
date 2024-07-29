class Solution {
public:
    int minCoins(int idx, int target, vector<int>& coins, vector<vector<int>>& dp)
    {
        if(idx == 0)
        {
            if(target%coins[idx] == 0) return target/coins[idx];
            else return 1e9;
        }

        if(dp[idx][target] != -1) return dp[idx][target];

        int non_take = minCoins(idx - 1, target, coins, dp) + 0;
        int take = 1e9;
        if(target >= coins[idx]) take = 1 + minCoins(idx, target - coins[idx], coins, dp);

        return dp[idx][target] = min(take, non_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        int res = minCoins(n-1, amount, coins, dp);
        if(res == 1e9) return -1;
        return res;
    }
};