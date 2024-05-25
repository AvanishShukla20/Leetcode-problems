class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 1) return s.size();
        /* this hash stores character in ascii code vs index*/
        int hash[256];
        for(int i=0; i< 256; i++)
        {
            hash[i] = -1;
        }

        int i=0, j = 0, n = s.size();
        int ans = INT_MIN;

        while(j < n)
        {
            if(hash[s[j]] != -1)
            {
                if(hash[s[j]] >= i)
                {
                    /* handles case for c in cadbzabcd */
                    i = hash[s[j]] + 1;
                }
            }

            ans = max(ans, j - i + 1);
            hash[s[j]] = j;
            j++; 
        }
        return ans;  
    }
};