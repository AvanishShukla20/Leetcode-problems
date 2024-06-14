class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        // make hash array of size = size of nums + max element of nums
        int n = nums.size();
        int m = *max_element(nums.begin(), nums.end());
        vector<int> freq(n + m+1, 0);


        for(int i =0; i < n; i++)
        {
            freq[nums[i]]++;
        }

        int ans =0, extra;

        for(int i=0; i<n+m+1; i++)
        {
            // i.e either doesn't exists or unique exists
            if(freq[i] <= 1) continue; 
            else
            {
                //duplicate exists
                //shift the extra frequency to next index element in freq
                extra = freq[i] - 1;
                freq[i+1] += extra;
                ans += extra;
            }
        }
        return ans;

    }
};