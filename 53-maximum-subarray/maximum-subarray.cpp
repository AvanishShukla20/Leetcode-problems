class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n+1);
        prefix[0] = 0;
        for(int i=1; i<=n; i++)
        {
            prefix[i] = nums[i-1] + prefix[i-1];
        }

        int mini = 0;
        int ans = INT_MIN;
        for(int i=1; i<=n; i++)
        {
            ans = max(ans, prefix[i] - mini);
            mini = min(mini, prefix[i]);
        }

        return ans;
    }
};