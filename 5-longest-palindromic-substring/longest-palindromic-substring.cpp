class Solution {
public:
    bool ispalindrome(int i, int j, string&s)
    {
        while(i <= j)
        {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        int maxi = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=n-1; j>=i; j--)
            {
                if(s[i] == s[j])
                {
                    if(ispalindrome(i, j, s))
                    {
                        if(j-i+1 > maxi)
                        {
                            ans = s.substr(i, j-i+1);
                            maxi = j - i + 1;
                        }
                    }
                }
                
            }
        }
        return ans;
    }
};