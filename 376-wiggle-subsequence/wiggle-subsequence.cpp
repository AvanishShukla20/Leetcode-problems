class Solution {
public:
    int dp[1002][1002][2];
    int solve(int idx,int prev, int grt, vector<int>& nums) // grt = 1 means greater required
    {
        if(idx == nums.size()) return 0;
        if(dp[idx][prev+1][grt] != -1) return dp[idx][prev+1][grt];
        int ans = 0;

        if(prev == -1 || grt == 1)
        {
            if(prev == -1 || nums[idx] > nums[prev]) ans = max(ans, 1 + solve(idx+1,idx, 0, nums));
            ans = max(ans, solve(idx+1,prev, 1, nums));
        }
        if(prev == -1 || grt == 0)
        {
            if(prev == -1 || nums[idx] < nums[prev]) ans = max(ans, 1 + solve(idx+1,idx, 1, nums));
            ans = max(ans, solve(idx+1,prev, 0, nums));
        }

        return dp[idx][prev+1][grt] = ans;
    }
    int wiggleMaxLength(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, -1, 0, nums);
    }
};