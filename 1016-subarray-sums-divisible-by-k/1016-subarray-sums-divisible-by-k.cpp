class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int pfSum = 0, res = 0, rem;
        unordered_map<int,int> remCount;

        remCount[0] = 1;

        for(int i=0; i < nums.size(); i++)
        {
            pfSum += nums[i];
            rem = pfSum % k; 
            
            if(rem < 0) rem = rem + k; // to handle cases of negative remainder i added a +k factor in remainder
            if(remCount.find(rem) != remCount.end())
            {
                res += remCount[rem]; 
            }
            remCount[rem]++;
        }

        return res;
    }
};