class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=1, j=1;
        int cnt = 1;
        while(j<n)
        {
            if(nums[j-1] != nums[j])
            {
                nums[i] = nums[j];
                i++;
                cnt++;
            }
            j++;
        }
        return cnt;
    }
};