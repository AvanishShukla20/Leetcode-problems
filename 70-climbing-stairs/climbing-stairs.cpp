class Solution {
public:
    
    int helper(int n, int dp[])
    {
        if(n < 0) return 0;
        if(n == 0) return 1;
        if(dp[n] != -1) return dp[n];

        return dp[n] = helper(n-1, dp) + helper(n-2, dp);
    }
    int climbStairs(int n) {
        int dp[46];
        memset(dp, -1, sizeof dp);
        return helper(n, dp);
    }
};