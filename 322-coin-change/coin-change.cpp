class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, 1e9));

        for(int i = 0; i<= amount; i++)
        {
            if(i%coins[0] == 0) dp[0][i] = i/coins[0];
        }


        for(int idx = 1; idx < n; idx++)
        {
            for(int target = 0; target <= amount; target++)
            {
                int non_take = dp[idx - 1][target];
                int take = 1e9;
                if(target >= coins[idx]) take = 1 + dp[idx][target- coins[idx]];

                dp[idx][target] = min(take, non_take);
            }
        }


        return (dp[n-1][amount] == 1e9) ? -1 : dp[n-1][amount];
    }
};