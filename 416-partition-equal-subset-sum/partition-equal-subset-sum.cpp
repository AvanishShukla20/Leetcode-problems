class Solution {
public:
    bool solve(int idx, int target,vector<int>& nums, vector<vector<int>>&dp)
    {
        if(target == 0) return true;
        if(idx == 0)
        {
            if(nums[idx] == target) return true;
            return false;
        }

        if(dp[idx][target] != -1) return dp[idx][target];

        //pick but with a check ->
        bool pick = false;
        if(target >= nums[idx]) pick = solve(idx-1, target-nums[idx], nums, dp);
        //non-pick
        bool non_pick = solve(idx-1, target, nums, dp);

        return dp[idx][target] = pick || non_pick;

    }
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();
        for(int i = 0; i< n; i++)
        {
            totalSum += nums[i];
        }

        if(totalSum%2 != 0) return false;
        cout<<totalSum<<endl;
        int target = totalSum/2;

        vector<vector<int>> dp(n, vector<int> (target + 1, -1));
        return solve(n - 1, target, nums, dp);
        
    }
};