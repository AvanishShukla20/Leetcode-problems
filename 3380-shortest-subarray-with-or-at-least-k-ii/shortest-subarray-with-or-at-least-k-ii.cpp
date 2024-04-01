class Solution {
public:

    void cumulativeContribution(int num, vector<int>& b, bool toadd)
    {
        int i = 0;
        while(num > 0)
        {
            b[i] = b[i] + (toadd ? 1 : -1) * (num%2);
            num = num/2;
            i++;
        }
    }


    bool isbitVecValueMoreOrEqualK(int k, vector<int>& b)
    {
        int val = 0;
        // O(1) -> 
        for(int i=0; i < 32; i++)
        {
            if(b[i] != 0) val = val | (1<<i); 
        }
        return (val >= k);        
    }


    int minimumSubarrayLength(vector<int>& nums, int k) {
        
        // initialise a bit vector of size 32 with intially all positions set to 0
        vector<int> bitVec(32, 0);
        int ans = INT_MAX;

        //sliding window template ->
        int i=0, j=0, n = nums.size();
        while(j < n)
        {
            //contribution of nums[j]
            cumulativeContribution(nums[j], bitVec, true);

            // quick check -> 
            while(isbitVecValueMoreOrEqualK(k, bitVec) && i<=j)
            {
                ans = min(ans, j - i + 1);
                cumulativeContribution(nums[i], bitVec, false);
                /* false means ->we have to subtract the contribution of nums[i] from bitVec*/ 
                i++;
            }
            j++;
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};