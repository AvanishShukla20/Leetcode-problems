class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> pos, neg;

        for(int i=0; i< n; i++)
        {
            if(nums[i] > 0) pos.push_back(nums[i]);
            else neg.push_back(nums[i]);
        }
        
        /* 
        Observation if index = even -> put positive 
                                            else negative 
        */

        for(int i = 0; i< n; i++)
        {
            if(i%2 == 0)
            {
                nums[i] = pos[i/2];
            }
            else
            {
                nums[i] = neg[i/2];
            }
        }
        return nums;


    }
};