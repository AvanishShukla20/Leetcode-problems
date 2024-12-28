#include<cmath>
class Solution {
public:
    int isValid(int windsize,int k, vector<int>& vec, string& s)
    {
        if(windsize == 1)
        {
            int cnt1 =0, cnt2 = 0;
            int start = 1;
            for(auto &it : s)
            {
                if(it-'0' != start) cnt1++;
                start = !start;
            }

            if(cnt1 <= k) return true;

            start = 0;

            for(auto &it : s)
            {
                if(it-'0' != start) cnt2++;
                start = !start;
            }

            return cnt2 <= k;
        }


        int ans =0;
        for(int i =0; i<vec.size(); i++)
        {
            ans += floor(vec[i]/(windsize+1));
        }
        return ans <= k;
    }
    int minLength(string s, int numOps) {
        int n = s.size();
        vector<int> vec;
        int cnt = 1;
        int i =0, j = 1;
        while(j < n)
        {
            while(j<n && s[i] == s[j])
            {
                cnt++;
                j++;
            }
            vec.push_back(cnt);
            i = j;
            cnt = 1;
            j++;
        }

        int low = 1, high = n;
        int ans = n,mid;
        while(low<=high)
        {
            mid = low + (high-low)/2;
            if(isValid(mid,numOps, vec, s))
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }

        return ans;
    }
};