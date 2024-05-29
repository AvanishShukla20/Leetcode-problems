class Solution {
public:
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, -1, 0, 1};
    int n,m;
    bool isValid(int row, int col, int n, int m)
    {
        return (row >= 0 && row < n && col >= 0 && col < m);
    }

    void dfs(int row, int col,vector<vector<char>>& board, vector<vector<int>>& vis)
    {
        vis[row][col] = 1;

        for(int i=0; i<4; i++)
        {
            int nr = row + drow[i];
            int nc = col + dcol[i];

            if(isValid(nr, nc, n, m) && !vis[nr][nc] && board[nr][nc] == 'O')
            {
                dfs(nr, nc, board, vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
       n = board.size();
       m = board[0].size(); 
       vector<vector<int>> vis(n, vector<int>(m, 0));

       //along row 
       for(int i=0; i<m; i++)
       {
            if(!vis[0][i] && board[0][i] == 'O')
            {
                dfs(0, i, board, vis);
            }
            if(!vis[n-1][i] && board[n-1][i] == 'O')
            {
                dfs(n-1, i, board, vis);
            }
       }

       for(int i=0; i<n; i++)
       {
            if(!vis[i][0] && board[i][0] == 'O')
            {
                dfs(i, 0, board, vis);
            }
            if(!vis[i][m-1] && board[i][m-1] == 'O')
            {
                dfs(i, m-1, board, vis);
            }
       }

       for(int i= 0; i< n; i++)
       {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == 'O' &&  vis[i][j] == 0)
            {
                board[i][j] = 'X';
            }
        }
       }
    }
};