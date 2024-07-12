class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0,n = nums.size(), ans = 0, zeroCnt = 0;

        while(j < n)
        {
            if(nums[j] == 0) zeroCnt++;
            while(zeroCnt > k)
            {
                if(nums[i] == 0) zeroCnt--;
                i++;
            }

            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};