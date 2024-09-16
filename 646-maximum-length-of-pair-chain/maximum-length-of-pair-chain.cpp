class Solution {
public:
    int solve(int idx, int prev, vector<vector<int>>& pairs,vector<vector<int>>& dp)
    {
        int n = pairs.size();
        if(idx == n) return 0;
        if(dp[idx][prev+1] != -1) return dp[idx][prev+1];

        int s1 = 0, s2 = 0;

        if(prev == -1 || pairs[prev][1] < pairs[idx][0])
        {
            //take
            s1 = 1 + solve(idx + 1, idx, pairs,dp);
        }
        s2 = solve(idx+1, prev, pairs,dp);
        return dp[idx][prev+1] = max(s1, s2);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        vector<vector<int>> dp(3000, vector<int>(3000, -1));
        return solve(0, -1, pairs, dp);
    }
};