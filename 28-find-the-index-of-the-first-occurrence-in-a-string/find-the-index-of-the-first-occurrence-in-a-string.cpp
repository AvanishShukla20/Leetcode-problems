class Solution {
public:
    typedef long long ll;
    int mod = 1e9 + 7;
    ll hashOfSubstring(string& s, ll& multiplier, int m)
    {
        ll ans = 0, factor = 1;

        for(ll i = m-1; i>= 0; i--)
        {
            ans += ((s[i] - 'a')*factor)% mod;
            factor = (factor*multiplier)%mod;
        }
        return ans % mod; 
    }
    int strStr(string haystack, string needle) {
        //solving by POPULAR STRING MATCHING ALGORITHM -> karp-Robin
        int m = needle.size(), n = haystack.size();
        if(m > n) return -1;

        ll multiplier = 26, maxmultiply = 1;

        for(int i = 1; i<= m; i++) maxmultiply = (maxmultiply*multiplier)%mod; // maxmultiply = 26^m

        //take hash of shorter string i.e needle
        ll hashneedle = hashOfSubstring(needle, multiplier, m);
        ll hashwind = 0;
        for(int i = 0; i <= n - m; i++)
        {
            if(i == 0)
            {
                //take hash of first window
                hashwind = hashOfSubstring(haystack, multiplier, m);
            }
            else
            {
                //hash of subsequent windows
                hashwind = (  (hashwind * multiplier)%mod - ((haystack[i-1] - 'a')*maxmultiply)%mod + (haystack[i+m-1] - 'a')  + mod)%mod; // mod is added to avoid case when hashwind becomes negative
            }

            if(hashwind == hashneedle)
            {
                //still compare the strings as same hash does not guarantee same string
                for(int j = 0; j< m; j++)
                {
                    if(needle[j] != haystack[j + i]) break;
                    if(j == m-1) return i;
                }
            }
        }
        return -1;

    }
};