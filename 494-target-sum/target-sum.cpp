class Solution {
public:
    int CountWays(vector<int>& nums,int idx, int target,int count)
    {
        if(idx == nums.size())
        {
            if(count == target) return 1;
            else return 0;
        }
        
        int sumWay  = CountWays(nums, idx+1, target, count + nums[idx]);
        int diffWay = CountWays(nums, idx+1, target, count - nums[idx]);

        int totalWay = sumWay + diffWay ;
        return totalWay;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return CountWays(nums,0,target,0);
        
    }
};