class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> oddCntfreq;

        //We have Not used  j pointer here at any cost
        oddCntfreq[0] = 1;
        int oddcnt = 0, res = 0;
        for(int i=0; i< nums.size(); i++)
        {
            if((nums[i]&1) == 1) oddcnt++;
            oddCntfreq[oddcnt]++;
            // main condition ->
            
            if(oddCntfreq.find( oddcnt - k ) != oddCntfreq.end())
            {
                res += oddCntfreq[oddcnt - k];
            }

            
        }

        return res;
    }
};