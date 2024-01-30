class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        unordered_map<int, int> mpp;
        int i= 0, j=0, n = nums.size();

        int x = *max_element(nums.begin(), nums.end());

        while(j < n)
        {
            //iterate and measure freq of each idx no matter whether it is required or not
            mpp[nums[j]]++;
            while(mpp[x] >= k)
            {
                ans += n - j;
                mpp[nums[i]]--;
                i++;
            }
            j++;
        }
        return ans ; 
    }
};