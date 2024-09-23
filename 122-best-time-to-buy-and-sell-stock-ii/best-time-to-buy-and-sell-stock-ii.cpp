class Solution {
public:
    int solve(int idx, int buy, vector<int>& prices, vector<vector<int>>& dp)
    {
        if(idx == prices.size()) return 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];
        int pr1 = 0, pr2 = 0;
        if(buy == 0)
        {
            //buy this
            pr1 = -prices[idx] + solve(idx+1, 1, prices, dp);
            //not buy this
            pr2 = 0 + solve(idx+1, 0, prices, dp);
        }
        else
        {
            //sell
            pr1 = prices[idx] + solve(idx+1, 0, prices, dp);
            //don't sell
            pr2 = 0 + solve(idx+1, 1, prices, dp);
        }
        return dp[idx][buy] = max(pr1, pr2);
        
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2, -1));
        return solve(0, 0, prices, dp);
    }
};