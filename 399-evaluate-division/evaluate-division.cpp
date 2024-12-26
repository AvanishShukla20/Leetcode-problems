class Solution {
public:
    void solve(string& node, string& end, map<string, vector<pair<string,double>>>& mpp, double ans, double& res, unordered_set<string>& vis)
    {
        if(node == end)
        {
            res = ans;
            return;
        }
        vis.insert(node);
        vector<pair<string, double>> vec = mpp[node];
        for(auto &it : vec)
        {
            if(vis.find(it.first) == vis.end())
            {
                solve(it.first, end, mpp, ans*it.second, res, vis);
            }
        }

        vis.erase(node);
        return;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, vector<pair<string,double>>> mpp;
        unordered_set<string> st;
        for(int i=0; i<equations.size();i++)
        {
            st.insert(equations[i][1]);
            st.insert(equations[i][0]);
            mpp[equations[i][0]].push_back({equations[i][1], values[i]});
            mpp[equations[i][1]].push_back({equations[i][0], 1.0/values[i]});
        }

        unordered_set<string> vis;
        vector<double> vec;
        for(auto &it : queries)
        {
            if(st.find(it[1]) == st.end())
            {
                vec.push_back(-1.0);
            }
            else if(it[0] == it[1])
            {
                vec.push_back(1.0);
            }
            else
            {
                double ans = 1.0, res = -1.0;
                solve(it[0], it[1], mpp, ans, res, vis);
                vec.push_back(res);
            }
            
        }
        return vec;
    }
};