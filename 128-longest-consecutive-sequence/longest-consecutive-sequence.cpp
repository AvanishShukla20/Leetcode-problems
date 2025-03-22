class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n <= 1) return n;
        sort(nums.begin(), nums.end());

        int cnt = 1, ans = 1;

        for(int i=1; i<n; i++)
        {
            if(abs(nums[i] - nums[i-1]) <= 1)
            {
                if(nums[i] - nums[i-1] == 1) cnt++;
            }
            else cnt = 1;
            ans = max(ans, cnt);
        }

        return ans;
    }
};