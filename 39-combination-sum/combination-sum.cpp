class Solution {
public:
    void solve(int idx, vector<int>& nums, int target, vector<int>& temp, vector<vector<int>>& ans)
    {
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }
        if(idx < 0) return;

        if(target >= nums[idx])
        {
            temp.push_back(nums[idx]);
            solve(idx, nums, target-nums[idx], temp, ans);
            temp.pop_back();
        }

        solve(idx-1, nums, target, temp, ans);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        int sum = 0;
        vector<int> temp;
        vector<vector<int>> ans; 
        solve(n-1, candidates, target, temp, ans);
        return ans;
    }
};