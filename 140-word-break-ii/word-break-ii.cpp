class Solution {
public:
    void solve(int idx, string&s, string ans, vector<string>& res, unordered_set<string>& st)
    {
        if(idx >= s.size())
        {
            if(idx == s.size())
            {
                res.push_back(ans);
            }
            return;
        }
        
        
        
        int len = 1;
        
        while(len <= s.size())
        {
            string substri = s.substr(idx, len);
            cout<<substri<<endl;
            if(st.find(substri) != st.end())
            {
                string t = substri;
                //st.erase(substri);
                if(idx+len < s.size()) solve(idx+len, s, ans+substri+" ", res, st);
                else solve(idx+len, s, ans+substri, res, st);
                //st.insert(t);
            }
            len++;
        }
        return;
        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = wordDict.size();
        unordered_set<string> st;
        for(auto &it : wordDict)
        {
            st.insert(it);
        }

        vector<string> res;
        string ans = "";
        solve(0, s, ans, res, st);
        return res;
    }
};