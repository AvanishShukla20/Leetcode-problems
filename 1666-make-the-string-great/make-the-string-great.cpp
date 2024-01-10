class Solution {
public:
    string makeGood(string s) {
     stack<char> st;
     string ans = "";
     int i=0;
     while(i < s.size())
     {
        if(s[i] >= 'a' and s[i] <= 'z')
        {
            if(st.empty() || st.top() != abs(s[i]-32)) st.push(s[i]);
            else if(!st.empty()) st.pop();
        }
        else
        {
            if(st.empty() || st.top() != (s[i]+32)) st.push(s[i]);
            else if(!st.empty()) st.pop();
        }
         i++;
     }

     while(!st.empty())
     {
         ans = ans + st.top();
         st.pop();
     }
     reverse(ans.begin(), ans.end());
     return ans;  
    }
};