class Solution {
public:
    int num_ops(char ch1, char ch2)
    {
        int a1 = ch1 - ch2;
        int a2 = ch2 - ch1;
        if(a1 < 0) a1 += 26;
        if(a2 < 0) a2 += 26;
        return min(a1, a2);
    }

    int solve(int i, int j, int k, string& s, vector<vector<vector<int>>>& dp)
    {
        if(i == j) return 1;
        if(i>j) return 0;
        

        
        if(s[i] == s[j]) return dp[i][j][k] = 2 + solve(i+1, j-1, k, s, dp);

        if(dp[i][j][k] != -1) return dp[i][j][k];

        int ops1 = solve(i+1, j, k, s, dp);
        int ops2 = solve(i, j-1, k, s, dp);
        int ops3 = 0;
        int p = num_ops(s[i], s[j]);
        if(p <= k)
        {
            ops3 = 2 + solve(i+1, j-1, k-p, s, dp);
        }

        return dp[i][j][k] = max({ops1, ops2, ops3});

    }
    int longestPalindromicSubsequence(string s, int k) {
        int n=s.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(k+1, -1)));
        return solve(0, n-1, k, s, dp);
    }
};