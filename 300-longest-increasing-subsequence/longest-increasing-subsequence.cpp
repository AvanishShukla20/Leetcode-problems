class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1); /* dp[i] represents longest increasing subsequence uptill this idx i */
        int maxi = 1;
        for(int i = 0; i< n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i] && dp[i] < dp[j] + 1)  dp[i] = dp[j] + 1;
                maxi = max(maxi, dp[i]);
            }
        }

        return maxi;
    }
};