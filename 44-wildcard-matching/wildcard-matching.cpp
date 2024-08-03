class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(m+1, vector<bool> (n+1, false));

        dp[0][0] = true;

        for(int i = 1; i<= m; i++)
        {
            bool flag = true;
            //the all remaining i's MUST be '*' for returning true
            for(int w = 1; w <= i; w++) // because now both p and i are 1 based indexing
            {
                if(p[w - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }

        for(int i = 1; i<= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(p[i-1] == s[j-1] || p[i-1] == '?') dp[i][j] = dp[i-1][j-1];
                else if(p[i-1] == '*')
                {
                    dp[i][j] = dp[i][j-1] | dp[i-1][j]; 
                }
                else dp[i][j] = false;
            }
        }

        return dp[m][n];
    }
};