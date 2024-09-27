class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(k+1, vector<int>(k+1, -1)); // dp[currparity][prevparity]
        int n = nums.size(), ans = 0;

        for(int i =0; i<n; i++)
        {
            int currRem = nums[i]%k;

            for(int prevRem = 0; prevRem < k; prevRem++)
            {
                dp[currRem][prevRem] = max(dp[currRem][prevRem], 1 + dp[prevRem][currRem]);
                ans = max(ans,dp[currRem][prevRem]);
            } 

        }
        return ans + 1;
    }
};