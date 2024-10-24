class Solution {
public:
    int minSwaps(string s) {
        int i = 0, unbalanced = 0;
        stack<int> st;
        while(i < s.size())
        {
            if(s[i] == ']')
            {
                if(!st.empty()) st.pop(); // stack not empty means i have one opening baracket corresponding to this closing bracket
                else unbalanced++;
            }
            else
            {
                st.push(i);
            }
            i++;
        }

        int ans = unbalanced/2;
        
        if(unbalanced%2 != 0) ans += 1;
        return ans;
    }
};