class Solution {
public:
    static bool comparator(pair<int, int>&a, pair<int, int>&b)
    {
        if(a.first == b.first) return a.second > b.second;
        else return a.first < b.first;
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int i =0; i<nums.size(); i++) mpp[nums[i]]++;

        vector<pair<int, int>> vec;
        for(auto &it : mpp)
        {
            vec.push_back({it.second, it.first});
        }

        sort(vec.begin(),vec.end(), comparator);

        vector<int> res;

        for(auto &it : vec)
        {
            int freq = it.first;
            while(freq--)
            {
                res.push_back(it.second);
            }
        }

        return res;
    }
};