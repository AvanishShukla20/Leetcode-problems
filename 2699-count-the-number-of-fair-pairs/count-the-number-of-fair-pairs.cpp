class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long ans = 0;
         
        for(int i =0; i<n; i++)
        {
            int num = nums[i];
            // lower bound gives value of first el NOT LESS THAN given value
            int idx1 = lower_bound(nums.begin()+i+1, nums.end(), (lower-num)) - nums.begin();
            long len1 = idx1 - 1 - i;

            // upper bound gives value of element just greater then given value
            int idx2 = upper_bound(nums.begin()+i+1, nums.end(), (upper-num)) - nums.begin();
            long len2 = idx2 - 1 - i;

            ans += (len2 -len1);
        }

        return ans;
    }
};