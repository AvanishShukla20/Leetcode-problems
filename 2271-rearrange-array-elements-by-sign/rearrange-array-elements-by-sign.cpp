class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        queue<int> pos;
        queue<int> neg;
        for(int i=0; i< n; i++)
        {
            if(nums[i] > 0) pos.push(nums[i]);
            else neg.push(nums[i]);
        }
        
        bool pref = true;  // 0 -> positive preferred 
                        // 1 -> negative preferred

        for(int i = 0; i< n; i++)
        {
            if(pref == true)
            {
                nums[i] = pos.front();
                pos.pop();
            }
            else
            {
                nums[i] = neg.front();
                neg.pop();
            }
            pref = !pref;
        }
        return nums;


    }
};