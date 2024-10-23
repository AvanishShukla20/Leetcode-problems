class Solution {
public:
    bool checkValidity(string& str, string& word)
    {
        if(str.size() != word.size()) return false;
        int i = 0;
        for(; i<word.size(); i++)
        {
            if((str[i] != word[i]) && (str[i] != ' '))
            {
                // the cell is having a different character
                break;
            } 
        }
        if(i == word.size()) return true;

        //check if reverse of str can be matched with word
        i = 0;
        reverse(str.begin(), str.end());
        for(; i<word.size(); i++)
        {
            if((str[i] != word[i]) && (str[i] != ' '))
            {
                // the cell is having a different character
                break;
            }
        }
        if(i == word.size()) return true;
        return false;
    }
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int m= board.size(), n = board[0].size();

        //collecting strings horizontally and checking
        for(int i =0; i<m; i++)
        {
            for(int j =0; j<n; j++)
            {
                while(j < n && board[i][j] == '#') j++;
                string str = "";
                while(j < n && board[i][j] != '#')
                {
                    str += board[i][j];
                    j++;
                }
                if(checkValidity(str, word) == true) return true;
            }
        }

        //collecting strings vertically and checking
        for(int i =0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                while(j < m && board[j][i] == '#') j++;
                string str = "";
                while(j < m && board[j][i] != '#')
                {
                    str += board[j][i];
                    j++;
                }
                if(checkValidity(str, word) == true) return true;
            }
        }
        return false;
    }
};