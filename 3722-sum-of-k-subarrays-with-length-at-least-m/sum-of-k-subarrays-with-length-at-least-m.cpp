class Solution {
public:
    vector<vector<long long>> dp;
    int maxSum(vector<int>& nums, int k, int m) {
        int n = nums.size();
        
        vector<long long> prefix(n+1, 0LL);
        for(int i = 1; i <= n; i++) prefix[i] = prefix[i-1] + nums[i-1]; // n

        dp.resize(n+1,vector<long long>(k+1,INT_MIN));
    
        for(int i = 0; i <= n; i++){ // n
            dp[i][0] = 0;
        }
    
        for (int j = 1; j <= k; j++) { // k
            long long bestOffset = INT_MIN;
            for (int i = 1; i <= n; i++) { // n
                dp[i][j] = dp[i-1][j]; // op1
                if (i - m >= 0) {
                    bestOffset = max(bestOffset, dp[i - m][j-1] - prefix[i - m]);
                }
                dp[i][j] = max(dp[i][j], prefix[i] + bestOffset);
            }
        }
        return dp[n][k];
    }
    // tc = O(n*k) = O(2000^2)
    // sc = O(n*k) = O(2000^2)
};