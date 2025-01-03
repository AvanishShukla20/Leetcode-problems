class Solution {
public:
    //int mod = 1000000007;
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long> sums(n);
        sums[n-1] = nums[n-1];

        for(int i=n-2; i>=0;i--)
        {
            sums[i] = sums[i+1] + nums[i];
        }

        int ans = 0;
        long sum = 0;
        for(int i=0; i<n-1; i++)
        {
            sum += nums[i];
            if(sum >= sums[i+1])
            {
                ans++;
            }
        }
        return ans;
    }
};