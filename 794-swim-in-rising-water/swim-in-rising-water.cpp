class Solution {
public:
    bool check(int i, int j, int limit, vector<vector<int>>& grid, vector<vector<int>>& vis)
    {
        int m=grid.size(), n=grid[0].size();
        if(grid[i][j] > limit) return false;
        if(i == m-1 && j == n-1) return true;
        
        vis[i][j] = 1;

        vector<vector<int>> dchange = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int cnt =0;
        for(int k=0; k<4; k++)
        {
            int ni = i+dchange[k][0];
            int nj = j+dchange[k][1];
            if(ni>=0&&ni<m&&nj>=0&&nj<n && !vis[ni][nj])
            {
                if(check(ni, nj,limit, grid, vis) == true) return true;
            } 
        }

        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int low = 0, mid;
        int ans = -1;
        int m=grid.size(), n=grid[0].size();
        int high = 0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                high = max(high, grid[i][j]);
            }
        }
        
        
        while(low <= high)
        {
            mid = low + (high-low)/2;
            vector<vector<int>> vis(m, vector<int> (n, 0));
            if(check(0, 0, mid, grid, vis) == true)
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        return ans;
    }
};