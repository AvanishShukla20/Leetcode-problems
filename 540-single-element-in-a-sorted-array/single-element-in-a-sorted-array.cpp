class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int seen = -1, n=nums.size();
        for(int i=0; i<n; i++)
        {
            if(seen == -1)
            {
                seen = nums[i];
            }
            else
            {
                if(seen == nums[i]) seen = -1;
                else break;
            }
        }

        return seen;
    }
};