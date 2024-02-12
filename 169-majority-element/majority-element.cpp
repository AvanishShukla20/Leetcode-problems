class Solution {
public:
    int majorityElement(vector<int>& nums) {

        /*
        BOYER MOORE ALGORITHM
        for any element to have ocurrence greater than N/2 its occurrence must Dominate
        over the total no of elements (other than this element) present in that array 
        */

        int ele = 0;
        int freq = 0;
        for(int i=0; i< nums.size(); i++)
        {
            if(freq == 0)
            {
                ele = nums[i];
                freq++;
            }
            else
            {
                if(nums[i] != ele) freq--;
                else freq++;
            }

        }

        return ele;
    }
};