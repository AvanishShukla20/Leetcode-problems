class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();

        while(k>0)
        {
            int minidx = -1;
            int mini = 1e9;
            for(int i = 0; i<n; i++)
            {
                if(nums[i] < mini)
                {
                    mini = nums[i];
                    minidx = i;
                }
            }

            nums[minidx] *= multiplier;
            k--;
        }
        

        
        return nums;
    }
};