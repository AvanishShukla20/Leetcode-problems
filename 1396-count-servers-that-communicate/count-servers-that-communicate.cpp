class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();

        vector<int> RowCnt(m, 0);
        vector<int> ColCnt(n, 0);

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1)
                {
                    RowCnt[i] += 1;
                    ColCnt[j] += 1;
                }
            }
        }

        int cnt =0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                
                if(grid[i][j] == 1)
                {
                    //presence of any single server other than current akes this current as communicable
                    // in row or in col
                    if(RowCnt[i] - 1 > 0 || ColCnt[j] - 1 > 0) cnt++;
                    
                }
            }
        }

        return cnt;
    }
};