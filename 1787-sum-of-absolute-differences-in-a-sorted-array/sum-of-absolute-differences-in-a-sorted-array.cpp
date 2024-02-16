class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int totalSum = 0, n = nums.size();
        int pfSum = 0;
        for(int i=0; i<n; i++)
        {
            totalSum += nums[i];
        }

        for(int i=0; i< n; i++)
        {
            pfSum += nums[i];
            int ele = nums[i];

            int res = ele*i + (totalSum - pfSum) - ( (pfSum - ele + ele*(n  - i - 1)) );
            nums[i] = res;
        }
        return nums;
    }
};