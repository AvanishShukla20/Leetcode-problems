class Solution {
public:
    int lcs(int i, int j, string& s, vector<vector<int>>& dp)
    {
        if(i == j) return 1;
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int l1 = 0, l2 = 0, l3 = 0;
        if(s[i] == s[j]) l1 = 2 + lcs(i+1, j-1, s, dp);
        else
        {
            l2 = lcs(i+1, j, s, dp);
            l3 = lcs(i, j-1, s, dp);
        }

        return dp[i][j] = max({l1, l2, l3});
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        return lcs(0, n-1, s, dp);
    }
};