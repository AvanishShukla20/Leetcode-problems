class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& vis)
    {
        int m = mat.size(), n = mat[0].size();
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, -1, 0, 1};

        vis[i][j] = 1;

        for(int d = 0; d<4; d++)
        {
            int nr = i + drow[d];
            int nc = j + dcol[d];

            if(nr >= 0 && nr < m && nc >= 0 && nc < n && mat[nr][nc] == 0 && !vis[nr][nc]) dfs(nr, nc, mat, vis);
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        // make a new matrix to represent the characters individually as a matrix

        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> mat( m*3, vector<int> ( n*3, 0));

        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                char ch = grid[i][j];

                if(ch == '\\')
                {
                    mat[i*3][j*3] = 1;
                    mat[i*3 + 1][j*3 + 1] = 1;
                    mat[i*3 + 2][j*3 + 2] = 1;
                }
                else if(ch == '/')
                {
                    mat[i*3][j*3 + 2] = 1;
                    mat[i*3 + 1][j*3 + 1] = 1;
                    mat[i*3 + 2][j*3] = 1;
                }
            }
        }

        //now just find the no of islands in this new matrix considering 0's as land and 1's as water ->

        vector<vector<int>> vis(m*3, vector<int> (n*3, 0));
        int cnt = 0;
        for(int i = 0; i<m*3; i++)
        {
            for(int j = 0; j < n*3; j++)
            {
                if(mat[i][j] == 0 && !vis[i][j])
                {
                    cnt++;
                    dfs(i, j, mat, vis);
                }
            }
        }

        return cnt;
    }
};