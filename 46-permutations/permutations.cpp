class Solution {
public:
    void solve(int i,vector<int>& nums,vector<int>& temp, vector<vector<int>>& vec,unordered_set<int>& st)
    {
        if(i == nums.size())
        {
            vec.push_back(temp);
        }

        for(int j = 0; j < nums.size(); j++)
        {
            if(st.count(j) == 0)
            {
                st.insert(j);
                temp.push_back(nums[j]);
                solve(i+1, nums, temp, vec, st);
                temp.pop_back();
                st.erase(j);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> vec;
        vector<int> temp;
        unordered_set<int> st;
        solve(0, nums, temp, vec, st);
        return vec;
    }
};