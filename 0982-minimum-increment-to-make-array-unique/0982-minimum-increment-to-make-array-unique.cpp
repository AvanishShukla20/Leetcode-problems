class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i-1] == nums[i])
            {
                ans += 1;
                nums[i] = nums[i]+1;
            }
            else if(nums[i-1] > nums[i]) // previous = 3 current = 2
            {
                ans += nums[i-1] + 1 - nums[i];

                nums[i] = nums[i-1] + 1;
            }
        }

        return ans;


    }
};