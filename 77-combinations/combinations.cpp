class Solution {
public:
    void solve(int idx, vector<int>&nums, vector<int>& temp, vector<vector<int>>& ans,unordered_set<int>& st, int k)
    {
        if(k == 0)
        {
            ans.push_back(temp);
            return;
        }
        if(idx == nums.size()) return;

        for(int i = idx+1; i<nums.size(); i++)
        {
            if(st.find(nums[i]) == st.end())
            {
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                solve(i, nums, temp,ans, st, k-1);
                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums(n);
        vector<vector<int>> ans;
        unordered_set<int> st;
        vector<int> temp;
        for(int i = 0; i<n; i++) nums[i] = i + 1;
        for(int i = 0; i<n; i++)
        {
            temp.push_back(nums[i]);
            st.insert(nums[i]);
            solve(i, nums, temp, ans, st, k-1);
            temp.pop_back();
            st.erase(nums[i]);
        }

        return ans;

    }
};