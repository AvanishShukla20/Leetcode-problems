class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();

        int mini = 0, ans = INT_MIN, cumSum = 0;

        for(int i=0; i<n; i++)
        {
            cumSum += nums[i];
            ans = max(ans, cumSum - mini);
            mini = min(mini, cumSum);
        }

        return ans;
    }
};