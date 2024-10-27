class Solution {
public:
    int mod = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {
        int n = s.size();
        vector<int> prev(26, 0);

        for(int i=0; i<n; i++) prev[s[i] - 'a']++;

        for(int itr = 1; itr <= t; itr++)
        {
            vector<int> curr(26, 0);
            for(int j = 0; j<26; j++)
            {
                if(prev[j] != 0)
                {
                    if(j == 25)
                    {
                        curr[0] = (curr[0] + prev[j])%mod;
                        curr[1] = (curr[1] + prev[j])%mod;
                    }
                    else
                    {
                        curr[j+1] = (curr[j+1] + prev[j])%mod;
                    }
                }
            }
            prev = curr;

        }

        int ans = 0;
        for(int i=0; i<26; i++) ans =  (ans + prev[i])%mod;
        return ans%mod;
    }
};