class Solution {
public:
    bool func(int i, int j, vector<vector<int>>& grid, int& col, vector<int>& ans)
    {
        int m=grid.size(), n=grid[0].size();
        if(i == m)
        {
            if(j < n) ans[col] = j;
            else ans[col] = -1;
            return true;
        }
        if(i<0||j<0||j>=n) return false;
        if(grid[i][j] == 1)
        {
            if(j+1 < n && grid[i][j+1] == -1) return false;
            return func(i+1, j+1, grid, col, ans);
        }
        else
        {
            if(j-1 >= 0 && grid[i][j-1] == 1) return false;
            return func(i+1, j-1, grid, col, ans);
        }

    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<int> ans(n, -1);
        if(n == 1) return ans;
        for(int p = 0; p<n; p++)
        {
            int col = p;
            func(0, p, grid, col, ans);
        }
        return ans;
    }
};