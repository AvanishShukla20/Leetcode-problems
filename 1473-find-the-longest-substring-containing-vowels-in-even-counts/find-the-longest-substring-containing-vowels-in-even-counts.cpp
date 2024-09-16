class Solution {
public:
    int findTheLongestSubstring(string s) {
        int hash[5] = {0};
        int n = s.size();
        unordered_map<int, int> mpp;
        mpp[0] = -1;
        int mask = 0, state = 0;
        int res = 0;

        for(int i=0; i<n; i++)
        {
            if(s[i] == 'a')
            {
                mask ^= (state|(1));
            }
            if(s[i] == 'e')
            {
                mask ^= (state|(1<<1));
            }
            if(s[i] == 'i')
            {
                mask ^= (state|(1<<2));
            }
            if(s[i] == 'o')
            {
                mask ^= (state|(1<<3));
            }
            if(s[i] == 'u')
            {
                mask ^= (state|(1<<4));
            }
            
            if(mpp.find(mask) != mpp.end()) res = max(res, i - mpp[mask]);
            else mpp[mask] = i;
        }

        return res;
    }
};