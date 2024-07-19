class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        unordered_map<int, int> rowmap;
        unordered_map<int, int> colmap;
        int n = matrix.size();
        int m = matrix[0].size();

        for(int row = 0; row < n; row++)
        {
            int mini = 1e6;
            for(int i =0; i<m; i++)
            {
                mini = min(mini, matrix[row][i]);
            }
            rowmap[row] = mini;
        }

        for(int col = 0; col < m; col++)
        {
            int maxi = -1;
            for(int i = 0; i < n; i++)
            {
                maxi = max(maxi, matrix[i][col]);
            }
            colmap[col] = maxi;
        }

        vector<int> ans;

        for(int i=0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == colmap[j] && matrix[i][j] == rowmap[i]) ans.push_back(matrix[i][j]);
            }
        }

        return ans;

    }
};