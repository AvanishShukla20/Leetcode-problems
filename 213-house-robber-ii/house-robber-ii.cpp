class Solution {
public:
    int solve(int i, int prev,int last_idx, vector<int>& nums, vector<vector<int>>& dp)
    {
        if(i >= last_idx)
        {
            return 0;
        }

        if(dp[i][prev+1] != -1) return dp[i][prev+1];

        int left = 0, right = 0;
        if(prev == -1 || i > prev+1)
        {
            left = nums[i] + solve(i+1, i, last_idx, nums, dp);    
        }


        right = solve(i+1, prev, last_idx, nums, dp);
        return dp[i][prev+1] = max(left, right);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        int ans1 = solve(0, -1, n-1, nums, dp);
        vector<vector<int>> dp2(n, vector<int>(n+1, -1));
        int ans2 = solve(1, -1, n, nums, dp2);
        return max(ans1, ans2);
    }
};