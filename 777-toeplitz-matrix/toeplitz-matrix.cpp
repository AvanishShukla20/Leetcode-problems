class Solution {
public:
    bool mark(int i, int j, vector<vector<int>>& matrix)
    {
        int m=matrix.size(), n= matrix[0].size();
        int val = matrix[i][j];
        while(i < m && j < n)
        {
            if(matrix[i][j] != val) return false;
            matrix[i][j] = -1;
            i++;
            j++;
        }
        return true;
    }
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(), n= matrix[0].size();

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j] != -1)
                {
                    bool x = mark(i, j, matrix);
                    if(x == false) return false;
                }
                
            }
        }

        return true;
    }
};