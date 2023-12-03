class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int i=0,j=0;
        int count=0;
        int maxCount=INT_MIN;
       while( i < nums.size() )
       {
           if(nums[i] == 0 )
           {
               if(count > maxCount) maxCount = count;
               while( j < i  )
               {   
                    if( nums[j] == 1) count--;
                    j++; 
               }
           }
            else
            {
                count++;
            }
            i++;
       }
       if(count > maxCount) maxCount = count;
       

       return maxCount; 
    }
};