class Solution {
public:
    string solve(string target,string& s,int score, int& ans)
    {
        stack<char> st;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == target[1] && !st.empty() && st.top() == target[0])
            {
                ans += score;
                st.pop(); 
            }
            else
            {
                st.push(s[i]);
            }
        }

        string str = "";

        while(!st.empty())
        {
            str += st.top();
            st.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
    int maximumGain(string s, int x, int y) {
        
        int ans = 0;

        int maxlen = (x > y) ? x : y;

        if(maxlen == y)
        {
            string received = solve("ba",s, y, ans);

            string temp = solve("ab",received, x, ans);
            //temp is of no use further
            temp.clear();
        }
        else
        {
            string received = solve("ab",s, x, ans);
            string temp = solve("ba",received, y, ans);
            //temp is of no use further
            temp.clear();
        }
        
        return ans;
        
    }
};