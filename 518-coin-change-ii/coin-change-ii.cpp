class Solution {
public:
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, 0));

        for(int i =0; i<=amount; i++)
        {
            if(i%coins[0] == 0) dp[0][i] = 1;
        }

        for(int idx = 1; idx < n; idx++)
        {
            for(int target = 0; target <= amount; target++)
            {
                int non_take = dp[idx - 1][target];
                int take = 0;
                if(target >= coins[idx]) take = dp[idx][target - coins[idx]];
                dp[idx][target] = non_take + take;
            }
        }

        return dp[n - 1][amount];
    }
};