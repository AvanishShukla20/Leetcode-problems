class Solution {
public:
    int calculateValidPairs(int Diff, vector<int>& nums)
    {
        int i = 0, j = 1, n = nums.size(), cnt = 0;

        while(j < n)
        {
            while(i < j && abs(nums[j] - nums[i]) > Diff) i++;
            int windowlen = j - i;
            cnt += windowlen;
            j++;
        }
        return cnt;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ldiff = 0, hdiff = nums[n-1], mid = 0, ans;

        while(ldiff < hdiff)
        {
            mid = ldiff + (hdiff - ldiff)/2;
            int validPairs = calculateValidPairs(mid, nums);
            cout<<"diff -> "<<mid<<" -> "<<validPairs<<endl;
            if(validPairs >= k)
            {
                //the greater diff must be containg the count of lower differences also .Hence,
                ans = mid;
                hdiff = mid;
            }
            else ldiff = mid + 1;
        }

        return ans;
    }
};