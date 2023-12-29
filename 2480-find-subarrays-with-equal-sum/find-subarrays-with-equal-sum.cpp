class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int i=0,j=1,n =nums.size();
        int sum=0;
        sum+=nums[0];
        while(j < n)
        {
            sum += nums[j];
            if(mpp.find(sum) != mpp.end())
            {
                return true;
            }
            mpp[sum]++;
            sum -= nums[i];
            i++;
            j++;
        }
        return false;
    }
};