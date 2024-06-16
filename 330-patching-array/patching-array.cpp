class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long patchCount = 0, i = 0, m = nums.size();
        long  maxSumAchieved = 1;

        while(maxSumAchieved <= n)
        {
            if(i < m && nums[i] <= maxSumAchieved)
            {
                maxSumAchieved += nums[i];
                i++;
            }
            else 
            {
                maxSumAchieved += maxSumAchieved;
                patchCount++;    
            }
        }
        return patchCount;
    }
};