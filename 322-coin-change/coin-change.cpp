class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1, 1e9);
        vector<int> curr(amount+1, 1e9);

        for(int i = 0; i<= amount; i++)
        {
            if(i%coins[0] == 0) prev[i] = i/coins[0];
        }


        for(int idx = 1; idx < n; idx++)
        {
            for(int target = 0; target <= amount; target++)
            {
                int non_take = prev[target];
                int take = 1e9;
                if(target >= coins[idx]) take = 1 + curr[target- coins[idx]];

                curr[target] = min(take, non_take);
            }

            prev = curr;
        }


        return (prev[amount] == 1e9) ? -1 : prev[amount];
    }
};