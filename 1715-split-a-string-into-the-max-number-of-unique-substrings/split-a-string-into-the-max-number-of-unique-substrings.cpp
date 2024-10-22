class Solution {
public:
    void solve(int idx, string&s, int& maxcount, int cnt, unordered_set<string> st)
    {
        if(idx == s.size()) 
        {
            maxcount = max(maxcount, cnt);
        }

        for(int j = idx; j < s.size(); j++)
        {
            string sub = s.substr(idx, j - idx + 1);
            if(st.find(sub) == st.end())
            {
                st.insert(sub);
                solve(j+1, s, maxcount, cnt+1, st);
                st.erase(sub);
            }
        }
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        int maxcount = 0;
        solve(0, s,maxcount, 0, st);
        return maxcount;
    }
};