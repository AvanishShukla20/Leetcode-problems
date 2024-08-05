class Solution {
public:
    int f(int idx, int buy, int cap, int& n, vector<int>& prices, vector<vector<vector<int>>>& dp)
    {
        if(cap == 2) return 0;
        if(idx == n) return 0;
        if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];

        int profit = 0;

        if(buy)
        {
            int Buythis = -prices[idx] + f(idx+1, 0, cap,n, prices,dp); // cap not incremented as curr transaction has not yet been completed
            int notBuythis = 0 + f(idx+1, 1, cap,n, prices,dp);
            profit = max(Buythis, notBuythis);
        }
        else
        {
            int sellthis = prices[idx] + f(idx+1, 1, cap+1,n, prices,dp); // transaction completed here
            int notsellthis = 0 + f(idx+1, 0, cap,n, prices,dp);
            profit = max(sellthis, notsellthis);
        }

        return dp[idx][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, -1)));

        return f(0, 1, 0, n, prices, dp);
    }
};