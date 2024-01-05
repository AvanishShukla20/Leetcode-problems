class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int idx;
        for(int i=0; i<nums.size(); i++)
        {
            idx = abs(nums[i]) -1;
            //mark this element  as -1*element

            if(nums[idx] > 0) nums[idx] = nums[idx] * -1;
        }

        //again iterating through modified array
        for(int i=0; i< nums.size(); i++)
        {
            if(nums[i] > 0)
            {
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};