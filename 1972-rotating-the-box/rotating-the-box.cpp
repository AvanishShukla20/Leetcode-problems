class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size(), m = boxGrid[0].size();
        vector<vector<char>> ans(m, vector<char> (n, '.'));

        
        
        for(int row = n-1; row >= 0; row--)
        {
            int prevcol = m-1;
            int mark = false;
            for(int col = m-1; col >= 0; col--)
            {
                if(prevcol >= 0 && boxGrid[row][col] == '#')
                {
                    ans[prevcol][n-1-row] = '#';
                    prevcol = prevcol-1;
                    mark = true;
                }
                else if(boxGrid[row][col] == '.' && !mark)
                {
                    prevcol = col;
                    mark = true;
                } 
                else if(boxGrid[row][col] == '*')
                {
                    ans[col][n-1-row] = '*';
                    prevcol = col-1;
                    mark = true;
                } 
                
            }
        }

        return ans;
    }
};