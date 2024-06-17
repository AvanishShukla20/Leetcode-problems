class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        st.push(num[0]);
        for(int i = 1; i < num.size(); i++)
        {
            while(!st.empty() && st.top() - '0' > num[i] - '0' && k > 0)
            {
                st.pop();
                k--;
            }

            //check and insert as leading zero should not be there
            if(st.size() > 0 || num[i] - '0' != 0) st.push(num[i]);

        }

        //note that we must have to make k as 0 . So , if it is not zero we will continue deleting numbers furthermore from stack

        while(k > 0 && !st.empty())
        {
            st.pop();
            k--;
        }

        if(st.empty()) return "0";

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