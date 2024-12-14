class Solution {
public:
    typedef long long ll;
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mpp; // this will keep elements in sorted fashion NOTE-> mpp.begin() gives samllest element and mpp.rbegin() gives largest element
        int i=0,j=0;
        ll ans = 0;
        while(j < n)
        {
            mpp[nums[j]]++;

            while(mpp.rbegin()->first - mpp.begin()->first > 2)
            {
                // shrink window
                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0) mpp.erase(nums[i]);
                i++;
            }

            ans += (j-i+1);
            j++;
        }
        return ans;
    }
};