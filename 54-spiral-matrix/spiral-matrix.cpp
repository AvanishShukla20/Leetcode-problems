class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int srcRow = 0, srcCol = 0, colbound = n - 1, rowbound = m - 1;
        int row = 0, col = 0;

        vector<int> ans;
        int dir = 0;
        while(srcRow <= rowbound && srcCol <= colbound)
        {
            if(dir == 0)
            {
                // left to right
                // constant: srcRow
                for(int i = srcCol; i <= colbound; i++)
                {
                    ans.push_back(matrix[srcRow][i]);
                }
                srcRow++;
            }
            if(dir == 1)
            {
                //top to down
                //constant: colbound
                for(int i=srcRow; i <= rowbound; i++)
                {
                    ans.push_back(matrix[i][colbound]);
                }
                colbound--;
            }
            if(dir == 2)
            {
                //right to left
                //constant: rowbound
                for(int i = colbound; i >= srcCol; i--)
                {
                    ans.push_back(matrix[rowbound][i]);
                }
                rowbound--;
            }
            if(dir == 3)
            {
                //down to up
                //constant: srcCol

                for(int i = rowbound; i >= srcRow; i--)
                {
                    ans.push_back(matrix[i][srcCol]);
                }
                srcCol++;
            }
            dir++;
            dir %= 4;
        }
        return ans;
    }
};