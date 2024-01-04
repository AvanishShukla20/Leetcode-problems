class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> countOccurence;
        int res =0;
        for(int i=0; i<nums.size(); i++)
        {
            countOccurence[nums[i]]++;
        }
        for(auto k : countOccurence)
        {
            if(k.second == 1)
            {
                res = -1;
                break;
            }
            else
            {
                // applying greed of getting multiple of 3 by subtracting 2 from every countvalue not divisible by 3
                while(k.second %3 != 0)
                {
                    k.second -= 2;
                    res +=1;
                }
                //now we get our count to be divisible by 3
                res += k.second/3;
            }
            
        }
        return res;
    }
};