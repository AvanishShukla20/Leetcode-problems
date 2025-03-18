class Solution {
public:
    typedef long long ll;
    ll getcost(ll v, vector<int>& nums, vector<int>& cost)
    {
        ll costs = 0;
        for(int i=0; i<nums.size(); i++)
        {
            costs += abs(v-nums[i])*cost[i];
        }

        return costs;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        ll low = 1, high = *max_element(nums.begin(), nums.end()), mid, ans = high;


        // note -> it may be possible that cost to reach low is greater than cost to reach high

        while(low <= high)
        {
            mid = low + (high-low)/2;
            ll cost_mid = getcost(mid, nums, cost);
            ll cost_mid_next = getcost(mid+1, nums, cost);
            if(cost_mid <= cost_mid_next)
            {
                ans = cost_mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }

        return ans;
    }
};