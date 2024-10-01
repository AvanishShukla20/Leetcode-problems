class Solution {
public:
    long long findSuitable(long long val,unordered_set<int>& st, vector<int>& maximumHeight)
    {
        int l = 1, h = val, res = 0, mid;
        while(l <= h)
        {
            mid = l + (h - l)/2;
            if(st.find(mid) == st.end())
            {
                res = mid;
                l = mid + 1;
            }
            else h = mid - 1;
        }
        return res == 0 ? -1 : res;
    }
    long long maximumTotalSum(vector<int>& maximumHeight) {
        int n = maximumHeight.size();
        sort(maximumHeight.rbegin(), maximumHeight.rend());
        unordered_set<int> st;
        long long ans = 0;
        for(int i=0; i<n; i++)
        {
            if(st.count(maximumHeight[i]) != 0)
            {
                long long val = findSuitable(maximumHeight[i],st, maximumHeight);
                if(val == -1) return -1;
                st.insert(val);
                ans += val;
            }
            else
            {
                ans += maximumHeight[i], st.insert(maximumHeight[i]);
            }
        }
        return ans;
    }
};