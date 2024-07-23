class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int> dp(n, 0);
        for(int i=0; i<n; i++)
        {
            if(obstacleGrid[0][i] != 0) break;
            else dp[i]++;
        }

        for(int row = 1; row < m; row++)
        {
            vector<int> current(n, 0);

            for(int col = 0; col < n; col++)
            {
                int up = 0, left = 0;
                if(obstacleGrid[row][col] == 0)
                {
                    if(col > 0) left += current[col-1];
                    up += dp[col];
                }
                current[col] = up + left;
            }
            dp = current;
        }

        return dp[n - 1];
    }
};