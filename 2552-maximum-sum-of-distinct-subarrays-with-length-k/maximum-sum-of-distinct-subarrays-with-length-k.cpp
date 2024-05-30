class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        long long ans = 0, sum = 0;

        for(int i=0; i<k; i++)
        {
            mpp[nums[i]]++;
            sum += nums[i];
        }
        if(mpp.size() == k) ans = max(ans, sum);
        int j = 0;
        for(int i = k; i < nums.size(); i++)
        {
            sum = sum + nums[i] - nums[j];
            mpp[nums[j]]--;
            if(mpp[nums[j]] == 0) mpp.erase(nums[j]);
            mpp[nums[i]]++;
            if(mpp.size() == k) ans = max(ans, sum);
            j++;
        }

        return ans;

    }
};