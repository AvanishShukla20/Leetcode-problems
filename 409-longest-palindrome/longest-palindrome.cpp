class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> st;
        int len = 0;
        for(int i=0; i< s.size(); i++)
        {
            if(st.find(s[i]) != st.end())
            {
                len += 2;
                st.erase(s[i]);
            }
            else st.insert(s[i]);
        }

        if(!st.empty()) return len + 1;
        return len;
          
    }
};