class Solution {
public:
    int maximumLength(vector<int>& nums) {
        vector<vector<int>> dp(2, vector<int>(2, -1)); // dp[currparity][prevparity]
        int n = nums.size(), ans = 0;

        for(int i =0; i<n; i++)
        {
            int parity = nums[i]%2;
            //010101 seq in subsequence

            dp[parity][!parity] = max(dp[parity][!parity], 1 + dp[!parity][parity]);
            // 111111111 or 00000000 sequnce in subsequence
            dp[parity][parity] = max(dp[parity][parity], 1 + dp[parity][parity]);

            ans = max({ans, dp[parity][!parity], dp[parity][parity]});

        }
        return ans + 1;
    }
};