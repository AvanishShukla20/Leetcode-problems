class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m =  mat[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> minDistance(n, vector<int>(m , 0));

        queue<pair<pair<int,int>, int>> Q;

        for(int i=0; i<n; i++)
        {
            for(int j =0; j<m; j++)
            {
                if(mat[i][j] == 0)
                {
                    Q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while(!Q.empty())
        {
            auto it = Q.front();
            int row = it.first.first;
            int col = it.first.second;
            int step = it.second;

            minDistance[row][col] = step;
            Q.pop();

            for(int i=0; i < 4; i++)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow>= 0 && ncol >= 0 && nrow < n && ncol < m && vis[nrow][ncol] == 0)
                {
                    vis[nrow][ncol] = 1;
                    Q.push({{nrow, ncol}, step + 1});
                }
            }

        }

        return minDistance;
    }
};