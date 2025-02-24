class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int , int> mpp;
        int n = nums.size();
        long long ans = 0;

        // calculating no off pairs that satisfy j - i == nums[j] - nums[i]
        // note above can be re arranged and written as -> nums[i] - i == nums[j] - j

        for(int i=n-1; i>=0; i--)
        {
            int diff = nums[i] - i;
            if(mpp.find(diff) != mpp.end())
            {
                ans += mpp[diff];
            }
            mpp[diff]++;
        }

        long long all = (1LL*n*(n-1))/2;
        long long res = all - ans;
        return res;
    }
};