class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        int reqVal = INT_MIN;
        int distcnt =0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++)
        {
            if(nums[i]-k > reqVal)
            {
                distcnt++;
                reqVal = (nums[i]-k)+1;
            }
            else if(reqVal <= (nums[i]+k))
            {
                distcnt++;
                reqVal++;
            }
        }
        return distcnt;
    }
};