class Solution {
public:
    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, -1, 0, 1};

    void dfs(int r, int c, vector<vector<char>>& board, vector<vector<int>>& vis, vector<vector<int>>& replica)
    {
        int m = board.size(), n = board[0].size();
        vis[r][c] = 1;
        replica[r][c] = 1;
        for(int i = 0; i<4; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && board[nrow][ncol] == 'O' && !vis[nrow][ncol])
            {
                dfs(nrow, ncol, board, vis, replica);
            }
        }
    }


    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<int>> replica(m, vector<int>(n, 0));

        //along row
        for(int i = 0; i < n; i++)
        {
            if(board[0][i] == 'O' && !vis[0][i]) dfs(0, i, board, vis, replica);
            if(board[m-1][i] == 'O' && !vis[m-1][i]) dfs(m-1, i, board, vis, replica);
        }
        // along column ->
        for(int i = 0; i < m; i++)
        {
            if(board[i][0] == 'O' && !vis[i][0]) dfs(i, 0, board, vis, replica);
            if(board[i][n-1] == 'O' && !vis[i][n-1]) dfs(i, n-1, board, vis, replica);
        }

        for(int row = 0; row < m; row++)
        {
            for(int col = 0; col < n; col++)
            {
                if(board[row][col] == 'O' && replica[row][col] == 0)
                {
                    board[row][col] = 'X';
                }
            }
        }

    }
};