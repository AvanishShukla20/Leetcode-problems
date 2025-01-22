class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n= isWater[0].size();
        vector<vector<int>> mat = isWater;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(isWater[i][j] == 1)
                {
                    mat[i][j] = 0;
                }
                else mat[i][j] = -1;
            }
        }


        vector<int> dr = {0, -1, 0, 1};
        vector<int> dc = {-1, 0, 1, 0};

        queue<pair<int, int>> q;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({i, j});                   
                }
            }
        }

        while(!q.empty())
        {
            auto r = q.front().first;
            auto c = q.front().second;
            q.pop();

            // assigning neighbours ->
            for(int k=0; k<4; k++)
            {
                int ni = r + dr[k];
                int nj = c + dc[k];

                if(ni>=0&&ni<m&&nj>=0&&nj<n && mat[ni][nj] == -1)
                {
                    mat[ni][nj] = mat[r][c] + 1;
                    q.push({ni, nj});
                }
            }
        }

        return mat;
    }
};