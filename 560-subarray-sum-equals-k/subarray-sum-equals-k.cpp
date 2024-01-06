class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //At each step calculate pSum and Then find if pSum-target appeared before or not 

        unordered_map<int, int> mpp;
        int pSum=0,res=0;
        mpp[pSum]++;
        for(int i=0; i<nums.size(); i++)
        {
            pSum += nums[i];
            if(mpp.find(pSum - k) != mpp.end())
            {
                res += mpp[pSum-k];
            }
            mpp[pSum]++;
        }
        return res;
    }
};