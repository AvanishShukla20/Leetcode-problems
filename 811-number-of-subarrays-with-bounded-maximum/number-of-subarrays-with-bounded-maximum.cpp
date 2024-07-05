class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        /* three cases ->*/

        int curridx = 0, endidx = 0, prevcnt = 0;
        long ans = 0;

        while(endidx < nums.size())
        {
            // if curr idx is in our range ->
            if(left <= nums[endidx] && nums[endidx] <= right)
            {
                // on very careful observation this will hit ->
                prevcnt = endidx - curridx + 1;
                ans = ans + prevcnt; 
            }
            else if(nums[endidx] < left)
            {
                /* yhi tum fase the ->   */

                //Do Dry run and find why to add previously calculated prevcnt value ONLY !!
                ans += prevcnt;

            }
            else
            {
                // reset the window ->
                curridx = endidx + 1;
                prevcnt = 0;
            }
            endidx++;
        }

        return ans;
    }
};