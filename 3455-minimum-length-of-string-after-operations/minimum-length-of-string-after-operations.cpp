class Solution {
public:
    int minimumLength(string s) {
        int n= s.size();
        unordered_map<char, int> lmpp;
        unordered_map<char, int> rmpp;

        for(auto &c : s) rmpp[c]++;
        int ans = n;
        for(int i=0; i<n; i++)
        {
                rmpp[s[i]]--;

                if(rmpp[s[i]] > 0 && lmpp[s[i]] > 0)
                {
                    //cout<<i<<" ";
                    lmpp[s[i]]--;
                    rmpp[s[i]]--;
                    ans -= 2;
                }
                lmpp[s[i]]++;
        }

        return ans;
    }
};