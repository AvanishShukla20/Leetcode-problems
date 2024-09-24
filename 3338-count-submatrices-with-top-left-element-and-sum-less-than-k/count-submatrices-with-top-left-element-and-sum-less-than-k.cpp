class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int ans = 0, m = grid.size(), n = grid[0].size();

        int pref = 0;
        for(int j = 0; j<n; j++)
        {
            pref += grid[0][j];
            if(pref <= k)
            {
                ans++;
            }
            else break;
        }
        pref = grid[0][0];
        for(int j = 1; j<m; j++)
        {
            pref += grid[j][0];
            if(pref <= k)
            {

                ans++;
            }
            else break;
        }

        vector<vector<int>> matrix = grid;

        for(int i = 0; i<m; i++)
        {
            for(int j = 1; j<n; j++)
            {
                matrix[i][j] += matrix[i][j-1];
            }
        }
        
        for(int i = 1; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                matrix[i][j] += matrix[i-1][j];
            }
        }

        for(int i = 1; i<m; i++)
        {
            for(int j = 1; j<n; j++)
            {
                if(matrix[i][j] <= k) ans++;
            }
        }
        

        return ans;
    }
};