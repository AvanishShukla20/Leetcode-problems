class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        bool x = false;

        int black = 0,white =0;

        for(int i=0; i<2; i++)
        {
            for(int j = 0; j<2; j++)
            {
                if(grid[i][j] == 'B') black++;
                else white++;
            }
        }
        if((black == 3 && white == 1) || (black == 1 && white == 3) || (black == 4) || (white == 4)) return true;

        black =0,white =0;
        for(int i=0; i<2; i++)
        {
            for(int j = 1; j<=2; j++)
            {
                if(grid[i][j] == 'B') black++;
                else white++;
            }
        }

        if((black == 3 && white == 1) || (black == 1 && white == 3) || (black == 4) || (white == 4)) return true;
        black =0,white =0;
        for(int i=1; i<=2; i++)
        {
            for(int j = 0; j<2; j++)
            {
                if(grid[i][j] == 'B') black++;
                else white++;
            }
        }

        if((black == 3 && white == 1) || (black == 1 && white == 3) || (black == 4) || (white == 4)) return true;
        black =0,white =0;
        for(int i=1; i<=2; i++)
        {
            for(int j = 1; j<=2; j++)
            {
                if(grid[i][j] == 'B') black++;
                else white++;
            }
        }

        if((black == 3 && white == 1) || (black == 1 && white == 3) || (black == 4) || (white == 4)) return true;
        
        return false;
    }
};