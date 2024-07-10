class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;
        string mainfolder;
        for(int i = 0; i < logs.size(); i++)
        {
            if(st.empty())
            {
                if(logs[i] != "./" && logs[i] != "../")
                {
                    mainfolder = logs[i];
                    st.push(mainfolder);
                }
                else continue;
            }
            else if(logs[i] == "../")
            {
                if(!st.empty()) st.pop();
            }
            else if(logs[i] == "./") continue;
            else st.push(logs[i]);
        }

        return st.size();
    }
};