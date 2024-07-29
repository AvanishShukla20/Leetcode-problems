class Solution {
public:
    int solve(int idx, int target, vector<int>& nums, vector<unordered_map<int, int>>& dp)
    {
        if(idx == 0)
        {
            if(nums[0] == 0 && target == 0) return 2;
            if(nums[0] == abs(target)) return 1;
            return 0;
        }

        if(dp[idx].find(target) != dp[idx].end()) return dp[idx][target];

        int  minus = solve(idx -1, target - nums[idx],nums, dp);
        int plus =  solve(idx - 1, target + nums[idx], nums, dp);

        return dp[idx][target] = minus + plus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n);
        return solve(n-1, target, nums, dp);
    }
};