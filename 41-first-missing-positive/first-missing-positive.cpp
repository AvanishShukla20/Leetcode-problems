class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        if(nums[0] > 1) return 1;
        bool isone = false;
        for(int i=0; i<n; i++)
        {
            if(nums[i] == 1)
            {
                isone = true;
                break;
            }
        }

        if(isone == false) return 1;

        int ans = INT_MAX;

        for(int i=0; i<n-1; i++)
        {
            if(nums[i] > 0 && nums[i] < nums[i+1] - 1)
            {
                ans = min(ans, nums[i]+1);
            }
        }

        if(ans == INT_MAX) ans = nums[n-1] + 1;
        
        return ans;
    }
};