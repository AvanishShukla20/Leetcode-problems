class Solution {
public:
    bool ispalindrome(int i, int j, string&s, vector<vector<int>>& storedDp)
    {
        if(i > j) return true;
        if(storedDp[i][j] != -1) return storedDp[i][j];

        if(s[i] == s[j]) return storedDp[i][j] = ispalindrome(i+1, j-1, s, storedDp);
        return storedDp[i][j] = false;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        int maxi = 0;

        vector<vector<int>> storedDp(n, vector<int>(n, -1));

        for(int i=0; i<n; i++)
        {
            for(int j=n-1; j>=i; j--)
            {
                if(s[i] == s[j])
                {
                    if(ispalindrome(i, j, s,storedDp))
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