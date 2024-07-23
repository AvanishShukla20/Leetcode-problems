class Solution {
public:
    
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long> vec(n, 0);

        for(int i =0; i<n;i++)
        {
            vec[edges[i]] += i;
        }

        vector<pair<long, int>> nodepairs;

        for(int i =0; i < n; i++)
        {
            nodepairs.push_back({vec[i], i});
        }

        sort(nodepairs.begin(), nodepairs.end());
        int ans = -1;
        int freq = -1;

        for(auto &it : nodepairs)
        {
            if(it.first > freq)
            {
                ans = it.second;
                freq = it.first;
            }
        }

        return ans;
    }
};