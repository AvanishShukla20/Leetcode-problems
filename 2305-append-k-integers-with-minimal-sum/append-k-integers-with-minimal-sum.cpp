class Solution {
public:
    typedef long long ll;
    long long minimalKSum(vector<int>& nums, int k) {
        set<int> st(nums.begin(), nums.end());

        ll sum = 0;
        ll start = 1;

        while(k>0 && !st.empty())
        {
            int t = *st.begin();
            st.erase(st.begin());

            int gap = t - start;
            if(k >= gap)
            {
                k -= gap;
            }
            else break;
            sum += 1LL*(t)*(t-1)/2 - 1LL*(start)*(start-1)/2;
            start = t + 1;
        }
        
        ll end = start + k;
        sum += 1LL*(end)*(end-1)/2 - 1LL*(start)*(start-1)/2;
        return sum;
    }
};