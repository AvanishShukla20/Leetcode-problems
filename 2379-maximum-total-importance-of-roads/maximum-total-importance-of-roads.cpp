class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> degree(n);

        for(int i=0; i < roads.size(); i++)
        {
            degree[roads[i][0]]++;
            degree[roads[i][1]]++;
        }

        sort(degree.begin(), degree.end());
        long long imp = 1;
        long long ans = 0;

        for(int i=0; i< n; i++)
        {
            ans += (degree[i])*imp;
            imp++;
        }
        return ans;

    }
};