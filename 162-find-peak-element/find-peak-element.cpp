class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
        //Applying Binary search without sorting :) ->
        int s=1, e= n-2;
        //NOTE -> s is not taken as 0 to avoid unnecessary checking of 0th element smaller than 1st as its been done already in above if statement
        int mid = s+(e-s)/2;
        while(s <= e)
        {
            mid = s+(e-s)/2;

            if(nums[mid] > nums[mid-1] and nums[mid] > nums[mid+1])
            {
                break;
            }
            else if(nums[mid] < nums[mid+1])
            {
                s = mid+1;
            }
            else if(nums[mid] < nums[mid-1])
            {
                e= mid-1;
            }
        }
        return mid;
    }
};