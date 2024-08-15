class Solution {
public:
    void solve(int idx, vector<int>& nums,vector<vector<int>>& ans)
    {
        int n = nums.size();
        if(idx == n)
        {
            ans.push_back(nums);
            return;
        }
        
        unordered_set<int> st;

        for(int i = idx; i < n; i++)
        {
            if(st.find(nums[i]) == st.end())
            { 
                st.insert(nums[i]);
                swap(nums[i], nums[idx]);
                solve(idx+1, nums,ans);
                swap(nums[i], nums[idx]);
            }
        }  
    }


    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, nums, ans);
        return ans;

    }
};