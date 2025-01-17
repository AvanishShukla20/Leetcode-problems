class Solution {
public:
    bool func(int i, int j, vector<vector<int>>& grid, int& col)
    {
        int m=grid.size(), n=grid[0].size();
        if(i == m)
        {
            if(j >= n) return false;
            col = j;
            return true;
        }
        if(i<0||j<0||j>=n) return false;
        if(grid[i][j] == 1)
        {
            if(j+1 < n && grid[i][j+1] == -1) return false;
            return func(i+1, j+1, grid, col);
        }
        else
        {
            if(j-1 >= 0 && grid[i][j-1] == 1) return false;
            return func(i+1, j-1, grid, col);
        }

    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<int> ans(n, -1);
        if(n == 1) return ans;
        for(int p = 0; p<n; p++)
        {
            int col = -1;
            cout<<"p : "<<p<<endl;
            if(func(0, p, grid, col) == true)
            {
                ans[p] = col;
            }
        }
        return ans;
    }
};