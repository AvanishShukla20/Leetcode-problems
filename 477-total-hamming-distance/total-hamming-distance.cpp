class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i=0; i<=31; i++)
        {
            int setbits = 0, unsetbits =0;
            for(int j = 0; j<n; j++)
            {
                int num = nums[j];

                if((num&(1<<i)) != 0) setbits++;
                else unsetbits++;
            }

            ans += (setbits*unsetbits); // setbits*unsetbits is no pairs differing at ith bit position
        }
        return ans;
    }
};