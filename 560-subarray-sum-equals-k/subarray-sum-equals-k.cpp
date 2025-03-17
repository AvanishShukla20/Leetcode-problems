class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int pfSum = 0, n = nums.size(), ans = 0;
        mpp[0] = 1;

        for(int i=0; i<n; i++)
        {
            pfSum += nums[i];
            if(mpp.find(pfSum - k) != mpp.end())
            {
                ans += mpp[pfSum-k];
            }
            mpp[pfSum]++;
        }

        return ans;
    }
};