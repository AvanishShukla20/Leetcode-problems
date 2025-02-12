class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> mpp;
        for(auto &x : nums)
        {
            string s = to_string(x);
            long sum = 0;
            for(auto &ch : s)
            {
                sum += ch-'0';
            }
            mpp[sum].push_back(x);
        }

        for(auto &it : mpp)
        {
            sort(it.second.rbegin(), it.second.rend());
        }

        long long maxi = -1;
        long long sum = 0;
        for(auto &it : mpp)
        {
            if(it.second.size() > 1)
            {
                sum = it.second[0] + it.second[1];
                maxi = max(maxi, sum);
            }
        }

        return maxi;
    }
};