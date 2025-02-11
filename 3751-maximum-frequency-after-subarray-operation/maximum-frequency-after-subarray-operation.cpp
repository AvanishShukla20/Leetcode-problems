class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int, int> mpp;

        for(int i=0; i<n; i++)
        {
            mpp[nums[i]]++;
        }

        int maxi = 0, ans = 0;
        for(int val = 1; val <= 51; val++)
        {
            if(mpp.find(val) != mpp.end())
            {
                /* modified array as 
                if(nums[i] == k) assume nums[i] = -1
                if(nums[i] == val) assume nums[i] = 1
                else nums[i] = 0;
                and applied kadane's algo in which whenever i find sum < 0 i reinitialise sum = 0
                */
                int currsum = 0;
                for(int i=0; i<n; i++)
                {
                    if(nums[i] == k) currsum -= 1;
                    else if(nums[i] == val) currsum += 1;

                    if(currsum < 0) currsum = 0;
                    maxi = max(maxi, currsum);
                }
            }
        }
        ans = max(ans, mpp[k] + maxi); // ans = max value of freq of k + max sum obtained
        return ans;
    }
};