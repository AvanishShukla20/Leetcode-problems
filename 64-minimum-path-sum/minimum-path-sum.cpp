class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp)
    {
        if(i < 0 || j < 0) return 1e9;
        if(i == 0 && j == 0) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int s1 = grid[i][j] + solve(i-1, j, grid, dp);
        int s2 = grid[i][j] + solve(i, j-1, grid, dp);
        return dp[i][j] = min(s1, s2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return solve(m-1, n-1, grid, dp);
    }
};