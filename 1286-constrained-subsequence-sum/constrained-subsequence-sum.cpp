class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> dp = nums;
        int res = INT_MIN;
        res = max(res, dp[0]);

        priority_queue<pair<int, int>> pq;
        pq.push({dp[0], 0});

        for(int i=1; i<n; i++)
        {
            // in previous code 
            // for(int j=i-1; j>=0 && i-j <= k; j--)
            // {
                // this was redundant thing we were doing

            //     dp[i] = max(dp[i], dp[j]+nums[i]);
            //     res = max(res, dp[i]);
            // }

            // note that all we need is max possible dp[j] that i can have at current idx so that i-j<= k

            while(!pq.empty() && i-pq.top().second > k)
            {
                pq.pop();
            }
            
            if(!pq.empty())
            {
                dp[i] = max(dp[i], dp[i]+pq.top().first);
            }
            pq.push({dp[i], i});
            res = max(res, dp[i]);
        }
        return res;
    }
};