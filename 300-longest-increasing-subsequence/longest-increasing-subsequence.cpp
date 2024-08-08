class Solution {
public:
    int solve(int idx, int prev, vector<int>& nums, vector<vector<int>>& dp)
    {
        int n = nums.size();
        if(idx == n) return 0;
        if(dp[idx][prev+1] != -1) return dp[idx][prev+1];

        int t1 = 0, t2 = 0, t3 = 0;
        if( prev == -1 || nums[idx] > nums[prev])
        {
            //take 
            t1 = solve(idx+1, idx, nums, dp) + 1;
            //not_take
            t2 = solve(idx+1, prev, nums, dp);
        }

        t3 = solve(idx+1, prev, nums, dp);
        return dp[idx][prev + 1] = max(t1, max(t2, t3));
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return solve(0, -1, nums, dp);
    }
};