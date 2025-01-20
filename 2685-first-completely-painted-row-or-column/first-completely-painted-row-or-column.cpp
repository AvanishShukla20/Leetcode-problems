class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m= mat.size(), n=mat[0].size();
        vector<int> rgrid(m, 0);
        vector<int> cgrid(n, 0);
        unordered_map<int, pair<int, int>> mpp;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                mpp[mat[i][j]] = {i, j};
            }
        }


        int ans = -1;
        for(int i=0; i<arr.size(); i++)
        {
            int x = mpp[arr[i]].first, y = mpp[arr[i]].second;
            rgrid[x]++;
            cgrid[y]++;
            if(rgrid[x] == n || cgrid[y] == m)
            {
                ans = i;
                break;
            }
        }

        return ans;
    }
};