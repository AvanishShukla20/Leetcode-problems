class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int start = 0, end = n-1, k=0;

        while(k <= end)
        {
            if(nums[k]==2)
            {
                swap(nums[k], nums[end]);
                end--;
                continue;
                // k++;
                // no k++ is done here because -> of VERY IMP TESTCASE -> [2, 1, 2] or [1, 2, 0]
            }
            else if(nums[k]==0)
            {
                swap(nums[k], nums[start]);
                start++;
               
            }
            k++;

            
        }

    }
};