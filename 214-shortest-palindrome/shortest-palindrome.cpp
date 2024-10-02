class Solution {
public:
    int lpsLen(string s)
    {
        vector<int> lps(s.size());
        lps[0] = 0;
        int i = 1;
        int length = 0;
        while(i < s.size())
        {
            if(s[i] == s[length])
            {
                length++;
                lps[i] = length;
                i++;
            }
            else
            {
                if(length != 0)
                {
                    length = lps[length - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        return lps[s.size() - 1];
    }
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        int longestPalindromicPrefix = lpsLen(s + '$' + rev);

        string ans = rev.substr(0, rev.size() - longestPalindromicPrefix) + s;
        return ans;
    }
};