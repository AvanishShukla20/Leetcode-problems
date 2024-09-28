class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;
        int prevdiff = nums[1] - nums[0];
        int currdiff = 0;

        int len = (prevdiff == 0) ? 1 : 2;
        
        for(int i = 2; i<n; i++)
        {
            currdiff = nums[i] - nums[i-1];
            if((prevdiff >= 0 && currdiff < 0) || (prevdiff <= 0 && currdiff > 0))
            {
                prevdiff = currdiff;
                len++;
            }
        }

        return len;

    }
};