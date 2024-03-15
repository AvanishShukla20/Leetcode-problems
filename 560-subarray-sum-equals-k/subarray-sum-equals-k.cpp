class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        /* We need to have the prefix sum for every index */

        int i=0, pfSum = 0, count = 0;
        /*freq map of pfSum for every index Vs no of times that pfsum appeared before that index */
        unordered_map<int, int> freq;
        freq[0] = 1;
        /* key of map is [pfSum - target] */
        while(i < nums.size())
        {
            pfSum += nums[i];
            if(freq.find(pfSum - k) != freq.end())
            {
                count += freq[pfSum-k];
            }
            freq[pfSum]++;
            i++;
        }
        return count;
    }
};