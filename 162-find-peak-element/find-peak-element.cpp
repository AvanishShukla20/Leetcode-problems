class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i=0,j=0,n = nums.size(),res;
        while(j < n-1)
        {
            if(nums[j+1] < nums[j])
            {
                res=j;
                break;
            }
            else if(nums[j+1] >= nums[j])
            {
                i = j;
                j++;
            }
        }
        return res;
    }
};