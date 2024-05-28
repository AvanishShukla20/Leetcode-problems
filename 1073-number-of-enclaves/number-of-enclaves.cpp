class Solution {
public:
    int count = 0, n, m;
    void dfs(int row, int col,vector<vector<int>>& grid, vector<vector<int>>& vis)
    {
        vis[row][col] = 1;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        for(int i =0; i<4; i++)
        {
            int nr = row + drow[i];
            int nc = col + dcol[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == 0 && grid[nr][nc] == 1)
            {
                count++;
                dfs(nr,nc,grid,vis);    
            }
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
         n = grid.size();
         m = grid[0].size();

        int Totalcnt = 0;
        for(int i=0; i<n; i++)
        {
            for(int j =0; j<m;j++)
            {
                if(grid[i][j] == 1)
                {
                    Totalcnt++;
                }
            }
        }


        vector<vector<int>> vis(n, vector<int>(m, 0));

        //first row and last row
        for(int j=0; j<m; j++)
        {
            if(!vis[0][j] && grid[0][j] == 1)
            {
                count++;
                dfs(0, j, grid,vis);
            }
            if(!vis[n-1][j] && grid[n-1][j] == 1)
            {
                count++;
                dfs(n-1, j, grid,vis);
            }
        }

        //first col and last col

        for(int i=0; i<n; i++)
        {
            if(!vis[i][0] && grid[i][0] == 1)
            {
                count++;
                dfs(i, 0, grid,vis);
            }
            if(!vis[i][m-1] && grid[i][m-1] == 1)
            {
                count++;
                dfs(i, m-1, grid,vis);
            }
        }

        

        return Totalcnt - count;

    }
};