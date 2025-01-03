class Solution {
public:
    int longestPath(int& r, int& c, vector<vector<int>>& matrix, vector<vector<int>>& dp)
    {
        if(dp[r][c] != 0) return dp[r][c];
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dpair = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        int maxi = 1;
        for(int i=0; i<4; i++)
        {
            int nrow = r + dpair[i][0];
            int ncol = c + dpair[i][1];

            if(nrow >=0&&nrow<m&&ncol>=0&&ncol<n&& matrix[r][c] < matrix[nrow][ncol])
            {
                maxi = max(maxi, 1+longestPath(nrow, ncol, matrix, dp));
            }
        }
        return dp[r][c] = maxi;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));
        int ans = 1;
        for(int i=0; i<m;i++)
        {
            for(int j=0; j<n; j++)
            {
                ans = max(ans, longestPath(i, j, matrix, dp));
            }
        }
        return ans;
    }
};