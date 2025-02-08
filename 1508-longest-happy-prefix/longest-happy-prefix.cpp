class Solution {
public:
    string lpS(string& s, vector<int>& lps)
    {
        int len =0, i = 1;
        
        int n=s.size();
        while(i < n)
        {
            
            if(s[i] == s[len])
            {
                
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if(len == 0)
                {
                    lps[i] = 0;
                    i++;
                }
                else len = lps[len-1];
            }
        }

        return s.substr(0, lps[i-1]); // lps pf last idx

    }
    string longestPrefix(string s) {
        int n=s.size();
        vector<int> lps(n, 0);
        return lpS(s, lps);
    }
};