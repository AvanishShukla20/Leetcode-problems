class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        unordered_map<int, int> mpp;
        unordered_map<int, int> colormap;
        vector<int> ans(n, 0);

        for(int i=0; i<n; i++)
        {
            if(mpp.find(queries[i][0]) != mpp.end())
            {
                colormap[mpp[queries[i][0]]]--;
                if(colormap[mpp[queries[i][0]]] == 0)
                {
                    colormap.erase(mpp[queries[i][0]]);
                }   
            }
            colormap[queries[i][1]]++;
            mpp[queries[i][0]] = queries[i][1];
            ans[i] = colormap.size();
        }

        return ans;
    }
};