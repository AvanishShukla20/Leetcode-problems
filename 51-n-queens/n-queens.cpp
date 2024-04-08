class Solution {
public:
    vector<vector<string>> ans;
    int N;
    bool isPlaceSafe(vector<string>& Board, int row, int col)
    {

        //check upwards
        for(int i = 0; i < row; i++)
        {
            if(Board[i][col] == 'Q') return false;
        }
        //check diagonal right upwards
        for(int i = row - 1, j = col + 1; i>=0 && j< N; i--, j++)
        {
            if(Board[i][j] == 'Q') return false;
        }

        // check diagonal left upwards
        for(int i = row - 1, j = col - 1; i>=0 && j >=0 ; i--, j--)
        {
            if(Board[i][j] == 'Q') return false;
        }

        return true;

    }
    void solveBoard(vector<string>& Board, int row)
    {
        if(row >= N)
        {
            ans.push_back(Board);
            return;
        }

        for(int col = 0; col < N ; col++)
        {
            if(isPlaceSafe(Board,row,col))
            {
                Board[row][col] = 'Q';
                solveBoard(Board, row+1);
                Board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {

        /* clever initialisation to a commonly used variable 
            by declaring it as global and initialising it in main function */
        N = n;
        vector<string> Board(n, string(n, '.'));
        solveBoard(Board, 0);
        return ans; 
    }
};