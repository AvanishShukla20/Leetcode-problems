class Solution {
public:
    long long dp[1000001][2];
    long long solve(int idx, int parIdx, vector<int>& nums)
    {
        if(idx == nums.size()) return 0;
        if(dp[idx][parIdx] != -1) return dp[idx][parIdx];

        long long maxi = 0;
        if(parIdx == 0) // it is even idx pos to be taken in subsequence 
        {
            maxi = max(maxi, nums[idx] + solve(idx+1, 1, nums));
            maxi = max(maxi, solve(idx+1, 0, nums));
        }
        else
        {
            maxi = max(maxi, -nums[idx] + solve(idx+1, 0, nums));
            maxi = max(maxi, solve(idx+1, 1, nums));
        }
        return dp[idx][parIdx] = maxi;
    }
    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, nums);
    }
};