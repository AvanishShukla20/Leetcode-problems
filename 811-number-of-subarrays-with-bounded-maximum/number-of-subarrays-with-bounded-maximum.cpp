class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int i = 0, j = 0, prev = 0, ans = 0;
        while(j < nums.size())
        {
            if(left <= nums[j] && nums[j] <= right)
            {
                prev = j - i + 1;
                ans += prev;
            }
            else if(nums[j] < left) ans += prev;
            else
            {
                i = j + 1;
                prev = 0;
            }
            j++;
        }
        return ans;
    }
};