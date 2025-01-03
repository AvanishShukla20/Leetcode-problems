class Solution {
public:
    void solve(int i, int j,vector<vector<int>>& heights, vector<vector<bool>>& vis)
    {
        int m = heights.size(),n=heights[0].size();

        vis[i][j] = 1;
        int dr[4] = {0, -1, 0, 1};
        int dc[4] = {1, 0, -1, 0};

        for(int k=0; k<4;k++)
        {
            int nr = i+dr[k];
            int nc = j+dc[k];

            if(nr>=0&&nr<m&&nc>=0&&nc<n && heights[i][j] <= heights[nr][nc] && !vis[nr][nc])
            {
                solve(nr, nc, heights, vis);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(),n=heights[0].size();

        vector<vector<int>> ans;
        vector<vector<bool>> markA(m, vector<bool>(n, false));
        vector<vector<bool>> markP(m, vector<bool>(n, false));

        for(int i=0;i<m;i++)
        {
            solve(i, 0, heights, markP);
            solve(i, n-1, heights, markA);
        }

        for(int j=0;j<n;j++)
        {
            solve(0, j, heights, markP);
            solve(m-1,j, heights, markA);
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(markA[i][j] == true && markP[i][j] == true)
                {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};