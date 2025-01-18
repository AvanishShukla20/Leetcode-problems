class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int> (n, 1));
        for(int i=0; i<mines.size(); i++)
        {
            int j =mines[i][0], k = mines[i][1];
            grid[j][k] = 0;
        }

        vector<vector<int>> dpup=grid, dpdown = grid, dpleft = grid, dpright = grid;

        for(int i=0; i<n; i++)
        {
            for(int j=1; j<n; j++)
            {
                if(dpleft[i][j] == 1)
                {
                    dpleft[i][j] = dpleft[i][j-1] + 1;
                }
                else dpleft[i][j] = 0;
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=n-2; j>=0; j--)
            {
                if(dpright[i][j] == 1)
                {
                    dpright[i][j] = dpright[i][j+1] + 1;
                }
                else dpright[i][j] = 0;
            }
        }

        for(int j=0; j<n; j++)
        {
            for(int i=1; i<n; i++)
            {
                if(dpup[i][j] == 1)
                {
                    dpup[i][j] = dpup[i-1][j] + 1;
                }
                else dpup[i][j] = 0;
            }
        }

        for(int j=0; j<n; j++)
        {
            for(int i=n-2; i>=0; i--)
            {
                if(dpdown[i][j] == 1)
                {
                    dpdown[i][j] = dpdown[i+1][j] + 1;
                }
                else dpdown[i][j] = 0;
            }
        }


        int ans =0;
        for(int i=0; i<n; i++)
        {
            for(int j =0; j<n; j++)
            {
                if(grid[i][j] == 1)
                {
                    int order = min({dpleft[i][j], dpright[i][j], dpup[i][j], dpdown[i][j]});
                    ans = max(ans, order);
                }
            }
        }
        return ans;
    }
};