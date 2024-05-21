class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& isVisited, vector<vector<char>>& grid)
    {
        isVisited[row][col] = 1;
        queue<pair<int, int>> Q;
        Q.push({row, col});

        vector<pair<int,int>> directions{{0,1},{0,-1},{1,0},{-1,0}};

        int n = grid.size();
        int m = grid[0].size();
        while(!Q.empty())
        {
            auto x = Q.front();
            int r = x.first;
            int c = x.second;
            Q.pop();

            for(int del= 0; del < directions.size(); del++)
            {
                    int newRow = r + directions[del].first;
                    int newCol = c + directions[del].second;

                    if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == '1' && isVisited[newRow][newCol] == 0 )
                    {
                        isVisited[newRow][newCol] = 1;
                        Q.push({newRow, newCol});
                    }
                
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        //new syntax learnt to declare a vector of vectors all initialised as 0
        vector<vector<int>> isVisited(n, vector<int>(m , 0));
        int count = 0;

        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m;j++)
            {
                if(grid[i][j] == '1' && isVisited[i][j] == 0)
                {
                    count++;
                    bfs(i, j, isVisited, grid);
                }
            }
        }
        return count;

    }
};