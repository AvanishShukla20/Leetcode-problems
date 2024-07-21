class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp(n, -1);

        dp[0] = nums[0];
        
        for(int i = 1; i < n; i++)
        {

            int inc = dp[i - 1];

            int exc = nums[i];
            if(i > 1) exc += dp[i - 2];

            dp[i] = max(inc, exc);
        }

        return dp[n - 1];
    }
};