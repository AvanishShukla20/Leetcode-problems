class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int n=deadends.size();
        unordered_set<string> st;

        for(int i=0; i<n; i++)
        {
            st.insert(deadends[i]);
        }

        string initial = "0000";
        if(st.find("0000") != st.end()) return -1;

        
        int lvl = 0;
        queue<pair<string, int>> q;
        q.push({initial, 0});
        st.insert(initial);

        while(!q.empty())
        {
            auto p = q.front();
            string s = p.first;
            int lvl = p.second;
            q.pop();

            if(s == target) 
            {
                return lvl;
            }


            string t = s;
            for(int i=0; i<4; i++)
            {
                char x = ((s[i]-'0') + 9)%10 + '0';
                char y = ((s[i]-'0') + 1)%10 + '0';

                t[i] = x;
                if(st.find(t) == st.end())
                {
                    q.push({t, lvl+1});
                    st.insert(t);
                }
                t[i] = y;

                if(st.find(t) == st.end())
                {
                    q.push({t, lvl+1});
                    st.insert(t);
                }
                t = s;
            }
        }

        return -1;
    }
};