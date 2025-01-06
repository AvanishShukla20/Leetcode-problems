class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int i, int j,int val,int& k, vector<vector<int>>& grid,vector<vector<vector<int>>>& dp)
    {
        if(i >= grid.size() || j >= grid[0].size()) return 0;
        val ^= grid[i][j];

        if(i == grid.size()-1 && j == grid[0].size()-1)
        {
            return (val == k);
        }

        if(dp[i][j][val] != -1) return dp[i][j][val];

        
        int s1 = solve(i, j+1,val,k, grid, dp)%mod;
        int s2 = solve(i+1, j,val,k, grid, dp)%mod;

        return dp[i][j][val] = (s1 + s2)%mod;
    }
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int m=grid.size(), n = grid[0].size();
        int val = 0;
        
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int> (17, -1)));
        return solve(0, 0, val, k, grid, dp);
    }
};