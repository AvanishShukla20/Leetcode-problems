class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n, 0);

        for(int i =0; i<n; i++)
        {
            if(i == 0) dp[i] = grid[0][i];
            else dp[i] = dp[i-1] + grid[0][i];
        }


        for(int i = 0; i < m; i++)
        {
            vector<int> curr(n, 0);
            if(i == 0) continue;
            for(int j = 0; j < n; j++)
            {
                int up = 1e9, left = 1e9;

                if(j > 0) left = curr[j-1] + grid[i][j];
                if(i > 0) up = dp[j] + grid[i][j];

                curr[j] = min(up, left);
            }

            dp = curr;
        }

        return dp[n-1];
    }
};