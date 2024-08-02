class Solution {
public:
    int longestPalindromicSubseq(int i, int j, string& s1, string& s2, vector<vector<int>>& dp)
    {
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]) return dp[i][j] = 1 + longestPalindromicSubseq(i-1, j-1, s1, s2, dp);
        else
        {
            return dp[i][j] = max(longestPalindromicSubseq(i-1, j, s1, s2, dp), longestPalindromicSubseq(i, j-1, s1, s2, dp));
        }
    }
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));

        string s1 = s;
        reverse(s1.begin(), s1.end());

        int lps = longestPalindromicSubseq(n-1, n-1, s,s1, dp);

        return s.size() - lps;
    }
};