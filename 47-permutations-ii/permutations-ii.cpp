class Solution {
public:
    void solve(int cnt, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans, unordered_map<int, int>& mpp)
    {
        if(cnt == nums.size())
        {
            ans.push_back(temp);
            return;
        }

        for(auto &it : mpp)
        {
            if(it.second != 0)
            {
                temp.push_back(it.first);
                it.second--;
                solve(cnt + 1, nums, temp, ans, mpp);
                temp.pop_back();
                it.second++;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        vector<vector<int>> ans;
        vector<int> temp;
        for(int &it : nums) mpp[it]++;
        solve(0, nums, temp, ans, mpp);
        return ans;

    }
};