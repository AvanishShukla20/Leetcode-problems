class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n <= 1) return 0;
        int ans = 0;
        
        int maxi = 0;

        for(int i=n-1; i>=0; i--)
        {
            ans = max(ans, maxi - prices[i]);
            maxi = max(maxi, prices[i]);

        }
        return ans;
    }
};