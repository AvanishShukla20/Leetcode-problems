class Solution {
public:
    int solve(int idx, int last_idx, int& n, vector<int>& nums, vector<vector<int>>& dp)
    {
        if(idx == n) return 0;
        
        if(dp[idx][last_idx + 1] != -1) return dp[idx][last_idx+1];

        int s1 = 0, s2 = 0;

        //take
        if(last_idx == -1 || nums[idx] > nums[last_idx]) s1 = solve(idx+1, idx, n, nums, dp) + 1;

        //not_take
        s2 = solve(idx+1, last_idx, n, nums, dp);

        return dp[idx][last_idx + 1] = max(s1, s2);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n + 1, -1));

        return solve(0, -1, n, nums, dp);
    }
};