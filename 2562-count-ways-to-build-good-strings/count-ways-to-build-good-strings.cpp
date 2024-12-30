class Solution {
public:
    int mod = 1000000007;
    int solve(int& len, int& low, int& high, int& one, int& zero, vector<int>& dp)
    {
        if(len > high) return 0;
        if(dp[len] != -1) return dp[len];

        long cnt = 0;
        
        if(len >= low && len <= high) cnt++;

        len += one;
        cnt += solve(len, low, high, one, zero, dp)%mod;
        len -= one;

        len += zero;
        cnt += solve(len, low, high, one, zero, dp)%mod;
        len -= zero;
        
        cnt %= mod;
        return dp[len] = cnt;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1, -1);
        int len = 0;
        return solve(len, low, high, one, zero, dp);
    }
};