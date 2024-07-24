class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // wherever you feel there is need of conversion of row into col OR VICE-VERSA apply TRANSPOSE OF MATRIX there
        int m = matrix.size();
        int n = m;
        for(int i = 0; i < m ; i++)
        {
            for(int j = i + 1 ; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i = 0; i<m; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }

        



    }
};