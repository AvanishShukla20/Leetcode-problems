class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        long long ans = 0;
        int m = grid.size(), n = grid[0].size();

        vector<long long> OnesInRow(m), OnesInCol(n);

        
        for(int i=0; i<m; i++)
        {
            long long cnt = 0;
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1) cnt++;
            }
            OnesInRow[i] = cnt;
        }

        for(int i=0; i<n; i++)
        {
            long long cnt = 0;
            for(int j=0; j<m; j++)
            {
                if(grid[j][i] == 1) cnt++;
            }
            OnesInCol[i] = cnt;
        }

        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1)
                {
                    ans += (OnesInRow[i] - 1)*(OnesInCol[j] - 1);
                }
            }
        }


        return ans;
    }
};