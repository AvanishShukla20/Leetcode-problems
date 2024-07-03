class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> grid(n+1, vector<int>(n+1, 1e9));

        for(int i = 1; i < n; i++)
        {
            grid[i][i] = 0;
            grid[i][i+1] = 1;
            grid[i+1][i] = 1;
        }
        grid[n][n] = 0;
        if(x != y)
        {
            grid[x][y] = 1;
            grid[y][x] = 1;
        }
        


        for(int midpath = 1; midpath <= n; midpath++)
        {
            for(int i =1; i <= n; i++)
            {
                for(int j = 1; j<=n; j++)
                {
                    if(i != j) grid[i][j] = min(grid[i][j], grid[i][midpath] + grid[midpath][j]);
                }
            }
        }


        vector<int> ans(n);

        for(int k = 1; k<= n; k++)
        {
            int cnt = 0;

            for(int i = 1; i<= n; i++)
            {
                for(int j = 1; j<= n; j++)
                {
                    if(grid[i][j] == k) cnt++;
                }
            }

            ans[k-1] = cnt;
        }
        return ans;
    }
};