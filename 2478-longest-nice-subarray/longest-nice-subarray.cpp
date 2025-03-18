class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int cum = nums[0];
        int j = 0;
        int ans = 1;
        for(int i=1; i<n; i++)
        {
            while(j<=i && (cum&nums[i]) != 0)
            {
                cum ^= nums[j];
                j++;
            }

            if((cum&nums[i]) == 0) ans = max(ans, i-j+1);
            cum |= nums[i];
        }

        return ans;
    }
};