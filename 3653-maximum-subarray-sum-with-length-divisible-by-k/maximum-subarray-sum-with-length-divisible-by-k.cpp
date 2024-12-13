class Solution {
public:
    typedef long long ll;
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        ll sum = 0, ans = -1e18;
        vector<ll> pfSum(n+1, 0);
        vector<ll> min_pfSum(n+1, 1e18);
        min_pfSum[0] = 0;
        pfSum[0] = 0;
        for(int i=1;i<=n; i++)
        {
            pfSum[i] = pfSum[i-1] + nums[i-1];
        }

        for(int i = 0; i<n ;i++)
        {
            ll minPrefixSum = min_pfSum[(i+1)%k];
            ll currPrefixSum = pfSum[i+1];
            if(minPrefixSum != 1e18) ans = max(ans, currPrefixSum - minPrefixSum);

            min_pfSum[(i+1)%k] = min(minPrefixSum, currPrefixSum);
        }

        return ans;
    }
};