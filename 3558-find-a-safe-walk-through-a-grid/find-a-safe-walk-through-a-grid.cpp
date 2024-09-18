class Solution {
public:
    bool solve(int i, int j,int health, vector<vector<int>>& grid, vector<vector<int>>& vis,vector<vector<vector<int>>>& dp)
    {
        int n = grid[0].size(), m = grid.size();
        if (i >= m || j >= n || i<0 || j<0 || health <= 0) return false;
        
        if(i == m-1 && j == n-1)
        {
            if(health > grid[i][j]) return true;
            return false;   
        }

        if(dp[i][j][health] != -1) return dp[i][j][health];

        vis[i][j] = 1;
        int drow[4] = {0, 1, 0, -1};
        int dcol[4] = {1, 0, -1, 0};
        int s = false;
        for(int p = 0; p < 4; p++)
        {
            int nr = i + drow[p];
            int nc = j + dcol[p];
            if(nr >= 0 && nc >= 0 && nr < m && nc < n && !vis[nr][nc])
            {
                
                if(grid[i][j] == 1) s |= solve(nr, nc,health - 1, grid, vis,dp);
                else s |= solve(nr, nc, health, grid, vis,dp);
            }
        }

        vis[i][j] = 0;
        return dp[i][j][health] = s;

    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid[0].size(), m = grid.size();
        
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (health + 2, -1)));
        vector<vector<int>> vis(m, vector<int> (n, 0));

        return solve(0, 0,health, grid, vis, dp);
    }
};