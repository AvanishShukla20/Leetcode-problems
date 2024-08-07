class Solution {
public:
    int findInsertionPlace(vector<int>& nums, int target)
    {
        int low = 0, high = nums.size()-1;
        int mid = low + (high - low)/2;

        while(low < high)
        {
            mid = low + (high - low)/2;
            if(nums[mid] == target) return mid;
            else if(target < nums[mid]) high = mid;
            else low = mid + 1;
        }
        return low;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        int len = 1;
        for(int i =0; i<n; i++)
        {
            if(nums[i] > temp.back())
            {
                temp.push_back(nums[i]);
                len++;
            }
            else 
            {
                int idx = findInsertionPlace(temp, nums[i]);
                temp[idx] = nums[i];
            }
        }

        return len;
    }
};