class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long pSum = 0;
        int n = nums.size();
        // calculate total sum upto index nums.size() - 2
        for(int i=0; i< n-1; i++)
        {
            pSum += nums[i];
        }
        long long ans = -1;
        //start algorithm

        int j = n-1;
        while(j > 0)
        {
            if(pSum <= nums[j])
            {
                j --;
                pSum -= nums[j];
            }
            else
            {
                ans = pSum + nums[j];
                break;
            }
        }
        return ans;        
    }
};