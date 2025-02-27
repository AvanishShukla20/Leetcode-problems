class Solution {
public:
    void checkExistence(string& part, stack<char>& t)
    {
        string p = "";

        while(!t.empty() && p.size() < part.size())
        {
            p += t.top();
            t.pop();
        }
        reverse(p.begin(), p.end());
        if(part == p)
        {
            return;
        }

        for(int i=0; i<p.size(); i++)
        {
            t.push(p[i]);
        }

    }
    string removeOccurrences(string s, string part) {
        stack<char> st;
        int n=s.size(), k=part.size();

        int i = 0;
        while(i < n)
        {
            st.push(s[i]);
            if(st.size() >= part.size())
            {
                checkExistence(part, st);
            }
            i++;
        }

        string ans = "";
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        cout<<ans<<endl;
        reverse(ans.begin(), ans.end());
        return ans;
    }
};