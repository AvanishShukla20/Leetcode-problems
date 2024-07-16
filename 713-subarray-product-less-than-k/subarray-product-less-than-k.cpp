class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int l = 0, r = 0, cnt = 0, n = nums.size();
        long pdt = 1;
        while(r < n)
        {
            pdt *= nums[r];

            while(pdt > k)
            {
                pdt /= nums[l];
                l++;
            }

            cnt += r - l + 1;
            if(pdt == k) cnt -= 1;
            r++;
        }
        return cnt;
    }
};