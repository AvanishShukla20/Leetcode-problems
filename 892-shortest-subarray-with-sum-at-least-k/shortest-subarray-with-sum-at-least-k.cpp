class Solution {
public:
    
    typedef long long ll;
    #define P pair<ll, int>
    int shortestSubarray(vector<int>& nums, int k) {
        int n= nums.size();
        vector<ll> prefix(n, 0);
        ll psum = 0;
        for(int i=0;i<n; i++)
        {
            psum += nums[i];
            prefix[i] = psum;
        }


        //priority queue for quick lookup of least prefixSum sum previously calculated which is nearest to my curr idx

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, -1});
        ll currSum = 0;
        int ans = 1e8;
        for(int i=0; i<n; i++)
        {
            currSum += nums[i];
            while(!pq.empty() && currSum - pq.top().first >= k)
            {
                ans = min(ans, abs(i - pq.top().second));
                pq.pop();
            }
            pq.push({currSum, i});
        }

        return ans == 1e8 ? -1 : ans;
    }
};