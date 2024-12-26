class Solution {
public:
    int solve(int idx, int& val,int& target, vector<int>& nums)
    {
        if(idx == nums.size())
        {
            if(val == target) return 1;
            return 0;
        }

        val += -1*nums[idx];
        int x = solve(idx+1, val, target, nums);
        val -= -1*nums[idx];

        val += nums[idx];
        int y = solve(idx+1, val, target, nums);
        val -= nums[idx];

        return x+y;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int val = 0;
        return solve(0, val, target, nums);
    }
};