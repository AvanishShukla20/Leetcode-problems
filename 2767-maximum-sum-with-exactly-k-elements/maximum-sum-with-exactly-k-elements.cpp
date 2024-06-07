class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
       int sum = 0;
       int m = *max_element(nums.begin(), nums.end());
       for(int i=0; i<k; i++)
       {
            sum += m;
            m++;
       }
       return sum; 
    }
};