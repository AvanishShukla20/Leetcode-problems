class Solution {
public:
    bool solve(int i, int target, vector<int>&nums, vector<int>& sides)
    {
        int n=nums.size();
        if(i == n) return true;

        // 4 means i need four diffrent sides or partitions

        for(int j=0; j<4; j++)
        {
            if(sides[j] + nums[i] <= target)
            {
                sides[j] += nums[i];
                if(solve(i+1, target, nums, sides) == true) return true;
                // backtrack
                sides[j] -= nums[i];
            }
        }

        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int n=matchsticks.size();
        int sum =0;
        sort(matchsticks.rbegin(), matchsticks.rend());
        for(int i=0; i<n; i++) sum += matchsticks[i];

        if(sum%4 != 0) return false;

        int target = sum/4;

        vector<int> sides(4, 0); // will contain each side length

        return solve(0, target, matchsticks, sides);
    }
};