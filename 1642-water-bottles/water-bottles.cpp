class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles, full = numBottles, done;

        while(full >= numExchange)
        {
            done = full/numExchange;
            ans += done;
            int rem = full%numExchange;

            full = done + rem;
        }
        return ans;
    }
};