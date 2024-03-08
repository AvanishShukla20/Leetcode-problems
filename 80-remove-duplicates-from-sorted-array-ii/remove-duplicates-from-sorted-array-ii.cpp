class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int i = 0, j = 0;
       while(i < nums.size())
       {
           if(i < 2)
           {
               i++; 
               j++;
           }
           else if(nums[i] != nums[j - 2])// check last second element
           {
               nums[j] = nums[i];
               j++;
               i++;
           }
           else
           {
               i++;
           }

       }
       return j; 
    }
};