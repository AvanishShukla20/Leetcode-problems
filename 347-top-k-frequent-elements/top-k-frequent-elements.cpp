class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for(int i=0;i<n;i++) mpp[nums[i]]++;
        vector<vector<int>> vec(n+1);

        // make idx of vec as freq and elements at ith index of it as a vector consisting elements with frequency i

        for(auto &it : mpp)
        {
            vec[it.second].push_back(it.first);
        }

        vector<int> ans;
        for(int freq = n; freq >= 0; freq--)
        {
            if(vec[freq].size() > 0 &&  k > 0)
            {
                ans.insert(ans.end(), vec[freq].begin(), vec[freq].end());
                k -= vec[freq].size();
            }
        }

        return ans;

    }
};