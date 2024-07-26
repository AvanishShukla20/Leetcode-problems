class Solution {
public:
    
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

        vector<vector<int>> dp(n, vector<int> (target + 1, 0));

        for(int i = 0; i < n; i++) dp[i][0] = 1;
        if(target >= nums[0]) dp[0][nums[0]] = 1;

        for(int idx = 1 ; idx < n; idx++)
        {
            for(int goal = 1; goal <= target; goal++)
            {
                //pick but with a check ->
                bool pick = false;
                if(goal >= nums[idx]) pick = dp[idx-1][goal-nums[idx]];
                //non-pick
                bool non_pick = dp[idx-1][goal];

                dp[idx][goal] = pick || non_pick;
            }
        }

        return dp[n-1][target];
        
    }
};