class Solution {
public:
    bool solve(int i, int j, string& s1, string& s2, vector<vector<int>>& dp)
    {
        if(i < 0)
        {
            if(j < 0) return true;
            return false;
        }

        if(j < 0)
        {
            //the all remaining i's MUST be '*' for returning true;
            for(int p = i; p >= 0; p--)
            {
                if(s1[p] != '*') return false;
            }
            return true;
        }


        if(dp[i][j] != -1) return dp[i][j];

        //recurrence ->

        if(s1[i] == s2[j] || s1[i] == '?') return dp[i][j] = solve(i-1, j-1, s1, s2, dp);
        if(s1[i] == '*')
        {
            return dp[i][j] = solve(i, j-1, s1, s2, dp) | solve(i-1, j, s1, s2, dp); 
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        return solve(m-1, n-1, p, s, dp);
    }
};