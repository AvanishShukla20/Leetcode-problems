class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minpq;
        priority_queue<pair<int, int>> maxpq;

        int n = arrays.size();

        for(int i =0; i<n; i++)
        {
            minpq.push({arrays[i][0], i});
            maxpq.push({arrays[i][arrays[i].size() - 1], i});
        }

        if(minpq.top().second != maxpq.top().second) return maxpq.top().first - minpq.top().first;
        else
        {
            int temp1 = minpq.top().first, temp2 = maxpq.top().first; 
            minpq.pop();
            maxpq.pop();
            int ans = max(temp2 - minpq.top().first, maxpq.top().first - temp1);
            return ans;
        }
    }
};