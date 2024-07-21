class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp(n, -1);

        dp[0] = nums[0];
        int neg = 0;
        for(int i = 1; i < n; i++)
        {

            int inc = dp[i - 1];
            
            int exc = 0;
            if(i > 1) exc = nums[i] + dp[i - 2];
            else exc = nums[i] + neg; // noob ki tarh likha taaki smjho

            dp[i] = max(inc, exc);
        }

        return dp[n - 1];
    }
};