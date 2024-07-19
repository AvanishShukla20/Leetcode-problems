class Solution {
public:

    int helper(vector<int>& coins, int amount, int dp[])
    {
        if(amount < 0) return INT_MAX; // invalid step tha isliye
        if(amount == 0)
        {
            return 0;
        } 

        if(dp[amount] != -1)
        {
            return dp[amount];
        }
        
        int res = INT_MAX;
        for(int i = 0; i< coins.size(); i++)
        {
            // decreasing amount everytime on selection of a coin
            int ans = helper(coins, amount - coins[i], dp);
            if(ans != INT_MAX) res = min(res, ans + 1);
        }
        return dp[amount] = res; 
    }
    int coinChange(vector<int>& coins, int amount) {

        int dp[10001];
        memset(dp, -1, sizeof dp);
        int ans = helper(coins, amount, dp);
        cout<<ans<<endl;

        if(ans == INT_MAX) return -1;

        return ans;
    }
};