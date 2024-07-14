class Solution {
public:
    void toposort(int u,bool& possible, stack<int>& st, vector<vector<int>>& adj,vector<int>& vis, vector<int>& isInCurrPath)
    {
        vis[u] = 1;
        isInCurrPath[u] = true;
        for(auto &it : adj[u])
        {
            if(!vis[it])
            {
                toposort(it,possible, st, adj, vis, isInCurrPath);
            }
            else if(isInCurrPath[it])
            {
                //pakka cycle h
                possible = false;
            }
        }

        isInCurrPath[u] = false;
        st.push(u);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // dfs approach uses a stack to store the order of elements
        vector<vector<int>> adj(numCourses);
        for(int i = 0; i< prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        stack<int> st;
        vector<int> vis(numCourses, 0);
        vector<int> isInCurrPath(numCourses, 0);
        bool possible = true;

        for(int i =0; i< adj.size(); i++)
        {
            if(!vis[i])
            {
                toposort(i,possible, st, adj, vis, isInCurrPath);
                if(possible == false) break;
            }
        }

        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        if(possible == false) return {};

        return ans;

    }
};