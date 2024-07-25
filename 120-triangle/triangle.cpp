class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // tabulation ->
        int m = triangle.size(), n = triangle[m-1].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i = 0; i< n; i++) dp[m-1][i] = triangle[m-1][i];

        // done for m-1 th row hwnce we will start from m-2 th row in for loop
        for(int i = m - 2; i>= 0; i--)
        {
            vector<vector<int>> curr(m, vector<int>(n, 0));
            for(int j = i; j>= 0; j--)
            {
                int down = dp[i+1][j] + triangle[i][j];
                int dig = dp[i+1][j+1] + triangle[i][j];

                dp[i][j] = min(down, dig);
            }
        }

        return dp[0][0];
    }
};