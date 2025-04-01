class Solution {
public:
    void solve(int idx, vector<int>& nums, int target, vector<int>& temp, set<vector<int>>& ans)
    {
        if(target == 0)
        {
            ans.insert(temp);
            return;
        }
        if(idx < 0) return;

        if(target >= nums[idx])
        {
            temp.push_back(nums[idx]);
            solve(idx-1, nums, target-nums[idx], temp, ans);
            temp.pop_back();
        }

        while(idx > 0 && nums[idx] == nums[idx-1]) idx--;
        
        solve(idx-1, nums, target, temp, ans);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        int sum = 0;
        vector<int> temp;
        set<vector<int>> ans;
        sort(candidates.begin(), candidates.end());

        solve(n-1, candidates, target, temp, ans);

        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};