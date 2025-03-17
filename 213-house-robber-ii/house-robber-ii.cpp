class Solution {
public:
    int solve(int i, int j, int prev, vector<int>& nums, vector<vector<int>>& dp)
    {
        if(i >= j) return 0;

        if(dp[i][prev+1] != -1) return dp[i][prev+1];

        int l = nums[i] + solve(i+2, j, i, nums, dp);
        int r = solve(i+1, j, prev, nums, dp);

        return dp[i][prev+1] = max(l, r);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        int ans1 = solve(0, n-1, -1, nums, dp);
        vector<vector<int>> dp2(n+1, vector<int> (n+1, -1));
        int ans2 = solve(1, n, -1, nums, dp2);

        return max(ans1, ans2);
    }
};