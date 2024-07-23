class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n  = nums.size();
        vector<int> freq(501, 0);
        for(int i =0; i<nums.size(); i++)
        {
            freq[nums[i]]++;
        }

        int res = true;

        for(int i = 0; i < freq.size(); i++)
        {
            if(freq[i]%2 != 0)
            {
                res = false;
                break;
            }
        }

        return res;

    }
};