class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char ch)
    {
        // horizontal and vertical check

        for(int i = 0; i < 9; i++)
        {
            if(board[i][col] == ch) return false;

            if(board[row][i] == ch) return false;
        }


        //check in sub - box
        int r = row - row%3;
        int c = col - col%3;

        for(int i = r; i < r + 3; i++)
        {
            for(int j = c; j < c + 3; j++)
            {
                if(board[i][j] == ch) return false;
            }
        }

        return true;
    }


    bool helper(vector<vector<char>>& board)
    {
        int n = board.size(), m = board[0].size();

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(board[i][j] == '.')
                {
                    for(char ch = '1'; ch <= '9'; ch++)
                    {
                        if(isValid(board, i, j, ch))
                        {
                            board[i][j] = ch;
                            if(helper(board) == true) return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};