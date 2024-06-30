class Solution {
public:
    int search(vector<int>& nums, int target) {
        // main idea is to search in sorted portion of array and eliminate and update search space accordingly
        int n = nums.size();
        int low = 0, high = n - 1;

        while(low <= high)
        {
            int mid = low + (high -low)/2;

            if(nums[mid] == target) return mid;

            if(nums[low] <= nums[mid]) // if left portion is sorted
            {
                if(nums[low] <= target && target <= nums[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else if(nums[mid] <= nums[high]) //right portion is sorted
            {
                if(nums[mid] <= target && target <= nums[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};