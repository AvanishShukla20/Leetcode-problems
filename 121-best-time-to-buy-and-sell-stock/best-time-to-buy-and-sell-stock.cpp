class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = prices[0], maxProfit = 0, profit;
        for(int i = 1; i < n ; i++)
        {
            profit = prices[i] - mini;
            maxProfit = max(maxProfit, profit);
            mini = min(prices[i], mini); 
        }

        return maxProfit;
    }
};