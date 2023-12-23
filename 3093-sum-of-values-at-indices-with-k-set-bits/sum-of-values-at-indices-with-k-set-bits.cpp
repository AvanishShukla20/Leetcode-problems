class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int count,sum=0;
        for(int i=0; i< nums.size(); i++)
        {
            count=0;
            for(int j=0; j<32; j++)
            {
                if((i & (1<<j)) != 0 ) count++;
            }
            if(count == k)
            {
                
                sum += nums[i];
            }
        }
        return sum;
    }
};