class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i =0,j=0;
        int sum = 0, ans = 1e6;
        while(j < n)
        {
            sum += nums[j];
            while(i <= j && sum >= target)
            {
                ans = min(ans, j-i+1);
                sum -= nums[i];
                i++;
            }
            if(sum >= target) ans = min(ans, j-i+1);
            j++;
        }
        return ans == 1e6 ? 0 : ans;
    }
};