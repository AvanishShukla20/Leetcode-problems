class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       int i=0, j = 0, n = nums.size();
       int prevFoundNoOfSubarrays = 0, oddcnt = 0, result = 0;

        // idea is -> when you get k  no of oddcnts .Then you add that cnt while shrinking the array. Meanwhile increasing the prevFoundNoOfSubarrays cnts
       while(i < n)
       {
        if(nums[i]%2 != 0)
        {
            oddcnt++;
            // Since We start our counting from here. So,We initialise prevFoundNoOfSubarrays from here first
            prevFoundNoOfSubarrays = 0;
        }

        while(oddcnt == k)
        {
            prevFoundNoOfSubarrays++;

            if(nums[j]%2 != 0) oddcnt--;
            j++;
        }

        result += prevFoundNoOfSubarrays;
        i++;
       }
       return result; 
    }
};