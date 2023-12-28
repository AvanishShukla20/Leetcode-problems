class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //element at last of each sorted subarray is the ans
        int j=0,res,n = nums.size();
        while( j< n-1 )
        {
            if(nums[j+1] < nums[j])
            {
                res = j;
                break;
            }
            else if(nums[j+1] >= nums[j])
            {
                j++;
            }
        }
        return res;
    }
};