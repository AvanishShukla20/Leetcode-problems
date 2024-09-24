class Solution {
public:
    int solve(vector<vector<int>>& grid, int col_y, int col_others)
    {

        int ans = 0, n = grid.size();
        for(int i=0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(((i <= n/2) && (i == j || i+j == n-1)) || (i > n/2 && j == n/2))
                {
                    if(grid[i][j] != col_y) ans++; 
                }
                else
                {
                    if(grid[i][j] != col_others) ans++;
                }
            }
        }

        return ans;
    }
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        return min({solve(grid, 0, 1), solve(grid, 1, 0),solve(grid, 1, 2),solve(grid, 2, 1),solve(grid, 2, 0),solve(grid, 0, 2)});
    }
};