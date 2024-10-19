class Solution {
public:
    typedef long long ll;
    int mod = 1e9 + 7;
    int solve(int i , int j, ll& sum, vector<vector<int>>& grid, int& k, vector<vector<vector<int>>>& dp)
    {
        if(i == 0 && j == 0)
        {
            int ans = 0;
            sum += grid[0][0];
            if(sum% k == 0) ans = 1;
            sum -= grid[0][0];
            return ans;
        }
        if(i < 0 || j < 0) return 0;
        if(dp[i][j][sum%k] != -1) return dp[i][j][sum%k];

        sum += grid[i][j];
        int up = solve(i-1, j, sum,grid, k, dp);
        int left = solve(i, j-1, sum,grid, k, dp);
        sum -= grid[i][j];
        return dp[i][j][sum%k] = (up%mod + left%mod)%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>> (n, vector<int> (k+1, -1)));
        ll sum = 0;
        return solve(m-1, n-1, sum, grid, k, dp);
    }
};