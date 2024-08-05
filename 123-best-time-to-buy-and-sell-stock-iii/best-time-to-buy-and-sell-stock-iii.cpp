class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> after(2, vector<int> (3, -1)), curr(2, vector<int> (3, -1));

        after[0][2] = 0;
        after[1][2] = 0;

        for(int b = 0; b<=1; b++)
        {
            for(int c = 0; c <= 2; c++)
            {
                after[b][c] = 0;
            }
        }


        for(int idx = n-1; idx >= 0; idx--)
        {
            curr[0][2] = 0;
            curr[1][2] = 0;
            for(int buy = 0; buy <= 1; buy++)
            {
                for(int cap = 1; cap >= 0; cap--)
                {
                    int profit = 0;

        if(buy)
        {
            int Buythis = -prices[idx] + after[0][cap]; 
            int notBuythis = 0 + after[1][cap];
            profit = max(Buythis, notBuythis);
        }
        else
        {
            int sellthis = prices[idx] + after[1][cap+1];
            int notsellthis = 0 + after[0][cap];
            profit = max(sellthis, notsellthis);
        }

        curr[buy][cap] = profit;
                }

                after = curr;
            }
        }

        return after[1][0];
    }
};