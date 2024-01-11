class Solution {
public:
    void GiveSubsets(int idx, vector<int>& ds ,vector<int>& nums,vector<vector<int>>& ans)
    {
        
        if(idx == nums.size())
        {
            ans.push_back(ds);
            return ;
        }

        ds.push_back(nums[idx]);
        GiveSubsets(idx+1, ds, nums,ans);
        ds.pop_back();

        GiveSubsets(idx+1, ds, nums,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int> ds;
        GiveSubsets(0, ds, nums, res);
        return res;
    }
};