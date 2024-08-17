class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int globalmin = arrays[0].front();
        int globalmax = arrays[0].back();
        int ans = 0;
        for(int i = 1; i<arrays.size(); i++)
        {
            int currmin = arrays[i].front();
            int currmax = arrays[i].back();

            // since hme different arrays se elements uthane the isliye pehle current ka difference wale operation swith iske pahle wale... kaam ko  pehle karenge then update krenge

            ans = max(ans, max(abs(globalmax - currmin), abs(globalmin - currmax)));

            globalmin = min(globalmin, currmin);
            globalmax = max(globalmax, currmax);
        }

        return ans;

    }
};