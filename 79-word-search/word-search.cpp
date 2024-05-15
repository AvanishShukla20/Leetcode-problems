class Solution {
public:
    int m,n;
    bool searchWord(vector<vector<char>>& board, int i, int j,int idx, string& word)
    {
        //check if we have done through all characters of word or not
        if(idx == word.size()) return true;

        if(i <0 || j<0 || i>=m || j>=n|| board[i][j] == '$') return false;
        if(board[i][j] != word[idx]) return false;

        //now we do our backtracking here

        char temp = board[i][j];
        board[i][j] = '$';

        // left,right,top,bottom
        bool p = searchWord(board, i - 1, j, idx+1, word) || searchWord(board, i+1, j, idx+1, word) || searchWord(board, i, j-1, idx+1, word) || searchWord(board, i, j+1, idx+1, word);


        board[i][j] = temp;
        return p;


    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        string temp = "";
        for(int i =0; i< m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(board[i][j] == word[0] && searchWord(board, i, j,0, word)) return true;
            }
        }
        return false;
    }
};