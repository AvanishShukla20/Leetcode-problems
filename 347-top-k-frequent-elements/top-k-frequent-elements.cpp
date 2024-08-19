class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //brute ->
        unordered_map<int, int> mpp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(int i=0; i<nums.size(); i++) mpp[nums[i]]++;
        
        for(auto &it : mpp)
        {
            if(pq.size() == k)
            {
                if(it.second > pq.top().first) pq.pop();
                else continue;
            }
            pq.push({it.second, it.first});
        }
        vector<int> ans;

        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;

    }
};