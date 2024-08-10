class Solution {
public:
    int f(int i, int j, vector<int>& nums, vector<vector<int>>&dp)
    {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int maxi = 0;
        for(int par = i; par <= j; par++)
        {
            int coins = nums[i-1]*nums[par]*nums[j+1] + f(i, par-1, nums, dp) + f(par+1, j, nums, dp);
            maxi = max(coins, maxi);
        }

        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return f(1, n, nums, dp);

    }
};