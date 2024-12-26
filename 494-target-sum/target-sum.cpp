class Solution {
public:
    int solve(int idx, int& val,int& target, vector<int>& nums, vector<unordered_map<int, int>> & dp)
    {
        if(idx == nums.size())
        {
            if(val == target) return 1;
            return 0;
        }

        if(dp[idx].find(val) != dp[idx].end()) return dp[idx][val];

        val += -1*nums[idx];
        int x = solve(idx+1, val, target, nums, dp);
        val -= -1*nums[idx];

        val += nums[idx];
        int y = solve(idx+1, val, target, nums, dp);
        val -= nums[idx];

        return dp[idx][val] = x+y;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int val = 0;
        vector<unordered_map<int, int>> dp(n+1);
        return solve(0, val, target, nums, dp);
    }
};