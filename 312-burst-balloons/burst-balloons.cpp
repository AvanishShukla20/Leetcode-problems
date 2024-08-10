class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

        for(int i = n; i >= 1; i--)
        {
            for(int j = i; j <= n; j++)
            {
                int maxi = 0;
                for(int par = i; par <= j; par++)
                {
                    // you must increase size of your dp array to n+2 in tabulation as par may require access of idx n+1
                    int coins = nums[i-1]*nums[par]*nums[j+1];
                    if(par > 1) coins += dp[i][par-1];
                    if(par < n ) coins += dp[par+1][j];
                    maxi = max(coins, maxi);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n];

    }
};