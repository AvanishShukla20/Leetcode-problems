class Solution {
public:
    typedef long long ll;
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        ll sum = 0, totalsum = 0;

        for(int x : nums) totalsum += x;
        if(totalsum < p) return -1;
        ll targetrem = totalsum%p;
        if(targetrem == 0) return 0;

        // we need to find min subarray len such that sum of subarray divided by p equals this targetrem
        ll prefix = 0;
        unordered_map<ll, int> mpp;
        mpp[0] = -1;
        int mini = n;
        for(int i = 0; i<n; i++)
        {
            prefix += nums[i];
            prefix %= p;

            int lookfor = (prefix - targetrem + p) % p;

            if(mpp.find(lookfor) != mpp.end())
            {
                mini = min(mini, i - mpp[lookfor]);
            }
            mpp[prefix] = i;
        }
        return (mini == n) ? -1 : mini;
    }
};