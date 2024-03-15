class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count = 0, sumSf = 0;
        unordered_map<int, int> mpp;
        mpp[0] =  1; // sum 0  at initial state before even start of traversal
        for(int i=0; i<nums.size(); i++)
        {
            sumSf += nums[i];
            if(mpp.find(sumSf - goal) != mpp.end())
            {
                count += mpp[sumSf - goal];
            }
            mpp[sumSf]++;
        }
        return count;
    }
};