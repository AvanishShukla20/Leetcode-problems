class Solution {
public:
    int solve(int i, int j, int cnt, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp)
    {
        if(i == 0 && j == 0)
        {
            if(cnt > 0 && grid[i][j] < 0) return 0;
            return grid[i][j];
        }
        if(dp[i][j][cnt] != INT_MIN) return dp[i][j][cnt];

        int x = INT_MIN;
        if(i > 0) x = grid[i][j] + solve(i-1, j, cnt, grid, dp);
        int y = INT_MIN;
        if(j > 0) y = grid[i][j] + solve(i, j-1, cnt, grid, dp);
        int z = INT_MIN, p = INT_MIN;

        if(grid[i][j] < 0 && cnt > 0)
        {
            if(i>0) z = solve(i-1, j, cnt-1, grid, dp);
            if(j>0) p = solve(i, j-1, cnt-1, grid, dp);
        }

        return dp[i][j][cnt] = max({x, y, z, p});
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int m=coins.size(), n= coins[0].size();
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int> (3, INT_MIN)));
        int cnt = 2;
        return solve(m-1, n-1,cnt, coins, dp);
    }
};