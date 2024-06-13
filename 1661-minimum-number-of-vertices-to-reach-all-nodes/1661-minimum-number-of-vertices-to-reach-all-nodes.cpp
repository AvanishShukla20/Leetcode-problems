class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>&adj, unordered_set<int>& s)
    {
        vis[node] = 1;

        for(auto &it: adj[node])
        {
            if(!vis[it])
            {
                dfs(it, vis, adj,s);
            }
            else
            {
                if(s.find(it) != s.end()) s.erase(it);
            }
        }
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
       vector<vector<int>> adj(n);
       vector<int> vis(n, 0);

       for(int i=0; i<edges.size(); i++)
       {
        adj[edges[i][0]].push_back(edges[i][1]);
       }


       unordered_set<int> s;

       for(int i=0; i<n; i++)
       {
            if(!vis[i])
            {
                dfs(i, vis, adj,s);
                s.insert(i);
            }
       }
       vector<int> ans;

       for(auto &x : s)
       {
        ans.push_back(x);
       }
       return ans;

    }
};