class Solution {
public:
    bool isValid(int row, int col, int n, int m)
    {
        return (row < n && row >= 0 && col < m && col >= 0);
    }


    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();

        int drow[4] = {0, -1, 0, 1};
        int dcol[4] = {1, 0, -1, 0};
        
        //remember always to use a minimal priority queue ...never declare priority queue as it is
        priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int, int>>>> q;
        vector<vector<int>> effort_grid(n , vector<int>(m, 1e9));

        q.push({0, {0, 0}});
        effort_grid[0][0] = 0;

        while(!q.empty())
        {
            auto top = q.top();
            int effortTillNow = top.first;
            int row = top.second.first;
            int col = top.second.second;
            q.pop();
            

            for(int i =0; i<4; i++)
            {
                int r = row + drow[i];
                int c = col + dcol[i];
                
                if(isValid(r, c, n , m))
                {
                    int ef = abs(heights[r][c] - heights[row][col]) ;
                    int newEffort = max(effortTillNow, ef);

                    if(newEffort < effort_grid[r][c])
                    {
                        effort_grid[r][c] = newEffort;
                        q.push({newEffort,{r,c}}); 
                    }
                }
                
            }

        }

        return effort_grid[n-1][m-1];
        
    }
};