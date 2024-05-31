class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        // here we are storing the idx of opening braces till seen in stack
        int n =  s.size();
        for(int i=0; i<n; i++)
        {
            if(s[i] == '(') st.push(i);
            else if(s[i] == ')')
            {
                int revBeginidx = st.top() + 1;
                int revEndidx = i;

                // error in line no 15 -> s.end()+ ... is not possible for reverse function
                reverse(s.begin() +revBeginidx, s.begin() + revEndidx);
                st.pop();
            }
        }

        string ans = "";
        for(int i=0; i<n; i++)
        {
            if(s[i] == '(' || s[i] == ')') continue;
            else ans += s[i];
        }
        return ans;


    }
};