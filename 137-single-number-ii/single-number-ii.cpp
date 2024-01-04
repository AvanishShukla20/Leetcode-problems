class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0,set;
        for(int i=0; i< 32; i++)
        {
            set =0;
            for(int j=0; j<nums.size(); j++)
            {
                if((nums[j] & (1<<i) ) != 0)set++;
            }
            // wrong ->  res |= (set % 3) << i; as set%3 can also give 2
            if(set%3 != 0)
            {
                res = res | (1 << i);
            }
            
        }
        return res;
    }
};