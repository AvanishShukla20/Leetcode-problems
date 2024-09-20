class Solution {
public:
    vector<int> solve(string st)
    {
        int n = st.size();

        vector<int> temp;
        for(int i =0; i<n; i++)
        {
            if(!isdigit(st[i]))
            {
            // take
            char op = st[i];
            vector<int> recl = solve(st.substr(0, i));
            vector<int> recr = solve(st.substr(i+1));

            for(int j=0; j<recl.size(); j++)
            {
                for(int k =0; k<recr.size(); k++)
                {
                    int res = 0;
                    if(op == '+') res = recl[j] + recr[k];
                    else if(op == '-') res = recl[j] - recr[k];
                    else res = recl[j]*recr[k];
                    temp.push_back(res);
                }
            } 
            }
        }

        if(temp.empty()) temp.push_back(stoi(st)); // if substring don not have any operator in it
        return  temp;
    }
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};