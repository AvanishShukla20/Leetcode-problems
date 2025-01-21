class Solution {
public:
    int solve(int i, int prev, bool& p, vector<int>& nums, vector<vector<vector<int>>>& dp)
    {
        if(i == nums.size())
        {
            return 0;
        }

        if(dp[i][prev+1][p] != -1) return dp[i][prev+1][p];

        int left = 0, right = 0;
        if(prev == -1 || i > prev+1)
        {
            if(i == 0)
            {
                p = true;
                left = nums[i] + solve(i+1, i, p, nums, dp);
                p = false;
            }
            else if(i == nums.size()-1 && p == true)
            {
                left = solve(i+1, prev, p, nums, dp);
            }
            else left = nums[i] + solve(i+1, i, p, nums, dp);    
        }


        right = solve(i+1, prev, p, nums, dp);
        return dp[i][prev+1][p] = max(left, right);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        bool p = false;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n+1, vector<int> (2, -1)));

        return solve(0, -1, p, nums, dp);
    }
};