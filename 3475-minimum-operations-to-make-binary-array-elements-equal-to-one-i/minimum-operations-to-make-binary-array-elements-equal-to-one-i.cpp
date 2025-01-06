class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size(), cnt = 0;

        for(int i=0; i<n-2; i++)
        {
            if(nums[i] == 0)
            {
                cnt++;
                nums[i] = !nums[i];
                nums[i+1] = !nums[i+1];
                nums[i+2] = !nums[i+2];
            }
        }

        int ans = cnt;

        for(int i=0; i<n; i++)
        {
            if(nums[i] == 0)
            {
                ans = -1;
                break;
            }
        }

        return ans;
    }
};