class Solution {
public:
     string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));

        for(int i =0; i<n; i++) dp[i][0] = 0;
        for(int i =0; i<m; i++) dp[0][i] = 0;

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(str1[i - 1] == str2[j - 1]) dp[i][j] = 1 + dp[i-1][j-1];
                else 
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        string ans = "";

        int idx1 = n, idx2 = m;

        while(idx1 > 0 && idx2 > 0)
        {
            if(str1[idx1 - 1] == str2[idx2 - 1])
            {
                ans += str1[idx1 - 1];
                idx1--;
                idx2--;
            }
            else if(dp[idx1 - 1][idx2] > dp[idx1][idx2 - 1])
            {
                ans += str1[idx1-1];
                idx1--;
            }
            else 
            {
                ans += str2[idx2 - 1];
                idx2--;
            }
        }

        while(idx1 > 0){
            ans += str1[idx1 - 1];
            idx1--;
        }
        while(idx2 > 0)
        {
            ans += str2[idx2 - 1];
            idx2--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};