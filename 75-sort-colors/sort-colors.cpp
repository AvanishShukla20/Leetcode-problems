class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> hash(3, 0);

        for(int i=0; i<nums.size(); i++)
        {
            hash[nums[i]]++;
        }

        int j = 0;
        for(int i = 0; i < 3; i++)
        {
            int freq = hash[i];
            while(freq)
            {
                nums[j] = i;
                j++;
                freq--;
            }
        }
        
    }
};