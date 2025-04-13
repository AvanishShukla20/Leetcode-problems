class Solution {
public:

    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int ans;
        int i=31;
        for(;i>=0; i--)
        {
            if( (n & (1<<i)) != 0) break;
        }
        int maxi = pow(2, i+1);

        ans = (n >= 3) ? maxi : n; 
        return ans;
    }
};