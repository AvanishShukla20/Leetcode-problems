class Solution {
public:
    int triangleNumber(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int diff, count = 0, n = nums.size(), j = 0, target;

        for (int i = n - 1; i >= 0; i--) {

            target = nums[i];
            int low = 0;
            int high = i -1;
            while(low < high)
            {
                if(nums[low]+nums[high] > target)
                {
                    count += (high-low);
                    high --;
                }
                else low++;
            }

        }
        return count;
    }
};