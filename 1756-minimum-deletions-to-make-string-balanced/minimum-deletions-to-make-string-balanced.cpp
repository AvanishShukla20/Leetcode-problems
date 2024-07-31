class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size(), cnt = 0;
        stack<char> st;
        for(int i = 0; i < n; i++)
        {
            if(st.empty()) st.push(s[i]);
            else if(st.top() == 'b' && s[i] == 'a')
            {
                st.pop();
                cnt++;
            }
            else st.push(s[i]);
        }

        return cnt;
    }
};