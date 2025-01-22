class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int, int> mpp;
        for(int i=0; i<n; i++) mpp[nums[i]]++;
        vector<unordered_set<int>> vec(n+1);
        for(auto &it : mpp)
        {
            vec[it.second].insert(it.first);
        }

        vector<int> ans;
        for(int j=vec.size()-1; j>=0; j--)
        {
            if(vec.size() > 0 && k > 0)
            {
                for(auto &t : vec[j])
                {
                    ans.push_back(t);
                    k--;
                    if(k == 0) break;
                }
            }
        }

        return ans;
    }
};