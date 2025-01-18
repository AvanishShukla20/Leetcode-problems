class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m=img.size(), n=img[0].size();
        vector<vector<int>> dchange = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1,1}, {-1, -1}, {1, -1}, {-1, 1}};
        vector<vector<int>> ans(m, vector<int> (n));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                int val = img[i][j];
                int cnt = 1;
                for(int k=0; k<8; k++)
                {
                    int ni = i + dchange[k][0];
                    int nj = j + dchange[k][1];

                    if(ni>=0&&ni<m&&nj>=0&&nj<n)
                    {
                        cnt++;
                        val += img[ni][nj];
                    }
                }

                ans[i][j] = val/cnt;
            }
        }

        return ans;
    }
};