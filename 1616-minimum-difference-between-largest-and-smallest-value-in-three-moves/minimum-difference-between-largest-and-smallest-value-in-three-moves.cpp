class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 4) return 0;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int choice1 = nums[n-4] - nums[0];
        int choice2 = nums[n-1] - nums[3];
        int choice3 = nums[n-3] - nums[1];
        int choice4 = nums[n-2] - nums[2];

        return min(choice1, min(choice2, min(choice3, choice4)));
    }
};