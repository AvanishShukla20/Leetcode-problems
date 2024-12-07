class Solution {
public:
    bool check(int& partition, int& maxOpr, vector<int>& nums)
    {
        int cnt = 0, n = nums.size();
        for(int i=0; i<n; i++)
        {
            cnt += nums[i]/partition;
            if(nums[i]%partition == 0) cnt -= 1;
        }
        return cnt <= maxOpr;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int mid, ans = high;

        while(low <= high)
        {
            mid = low + (high -low)/2;

            if(check(mid, maxOperations, nums) == true)
            {
                ans = mid;
                high = mid -1;
            }
            else low = mid+1;
        }
        return ans;
    }
};