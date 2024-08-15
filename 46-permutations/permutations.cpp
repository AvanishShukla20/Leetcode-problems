class Solution {
public:
    void solve(int idx,vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans, unordered_set<int>& st)
    {
       if(idx == nums.size())
       {
            ans.push_back(temp);
            return;
       }

       for(int i = 0; i< nums.size(); i++)
       {
        if(st.find(nums[i]) == st.end())
        {
            temp.push_back(nums[i]);
            st.insert(nums[i]);
            solve(idx + 1, nums, temp, ans, st);
            temp.pop_back();
            st.erase(nums[i]);
        }
       }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        unordered_set<int> st;
        solve(0, nums, temp, ans, st);
        return ans;
    }
};