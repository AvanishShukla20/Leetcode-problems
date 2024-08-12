class Solution {
public:
    int solve(int idx, vector<int>& nums, int& k, vector<int>& dp)
    {
        int n = nums.size();
        if(idx == n) return 0;
        if(dp[idx] != -1) return dp[idx];
        int maxi = nums[idx];
        int ans = 0, len = 0;
        for(int i = idx; i < min(n, idx + k); i++) // mistake you did -> if idx = n-1 and k > 1 then idx+k may increase bounds of n
        { 
            len++;
            if(nums[i] > maxi) maxi = nums[i];
            int pos = (len*maxi) + solve(i + 1, nums, k, dp);
            ans = max(ans, pos);
        }
        return dp[idx] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(0, arr, k, dp);
    }
};