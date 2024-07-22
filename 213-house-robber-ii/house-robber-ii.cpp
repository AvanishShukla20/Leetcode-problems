class Solution {
public:
    int solve(int idx, vector<int>& nums, vector<int>& dp)
    {
        if(idx < 0) return 0;

        if(dp[idx] != -1) return dp[idx];
        //include
        int left = solve(idx - 2, nums, dp) + nums[idx];
        //exclude
        int right = solve(idx - 1, nums, dp);

        return dp[idx] = max(left, right);
    }


    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> temp1, temp2;
        for(int i = 0; i < n; i++)
        {
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }

        vector<int> dp1(n , -1);
        vector<int> dp2(n, -1);
        return max( solve(temp1.size() - 1, temp1, dp1), solve(temp2.size() - 1, temp2, dp2));
    }
};