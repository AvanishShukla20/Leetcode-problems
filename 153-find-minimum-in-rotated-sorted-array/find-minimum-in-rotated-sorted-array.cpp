class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low =0, high = n-1, mid, ans = INT_MAX;
        while(low <= high)
        {
            mid = low+(high-low)/2;
            if(nums[mid] > nums[high]) low = mid+1;
            else
            {
                if(nums[mid] < ans) ans = nums[mid];
                high = mid-1;
            }
        }
        return ans;
    }
};