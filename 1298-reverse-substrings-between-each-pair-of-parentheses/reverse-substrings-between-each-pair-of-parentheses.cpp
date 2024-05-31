class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        int n = s.size(), i = 0;
        string temp;
        while(i < n)
        {
            if(s[i] == ')')
            {
                temp = "";
                while(!st.empty() && st.top() != '(')
                {
                    temp += st.top();
                    st.pop();
                }

                if(!st.empty())
                {
                    st.pop();
                }

                for(int j = 0; j < temp.size(); j++)
                {
                    st.push(temp[j]);
                }
            }
            else
            {
                st.push(s[i]);
            }
            i++;
        }

        string ans = "";
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};