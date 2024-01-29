class Solution {
public:
    char findTheDifference(string s, string t) {
        int xr = 0;

        for(int i=0; i<s.size(); i++)
        {
            xr ^= s[i]-'a';
        }

        for(int i=0; i<t.size(); i++)
        {
            xr ^= t[i]-'a';
        }
        char ans = xr +'a';
        return ans;
    }
};