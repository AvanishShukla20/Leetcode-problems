class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis)
    {
        vis[node] = 1;
        for(auto &it : adj[node])
        {
            if(!vis[it])
            {
                dfs(it, adj, vis);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);

        // reversed the edges so that travesal to ancestor node is very quick and hastle free-> 
        for(int i = 0; i < edges.size();i++)
        {
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<vector<int>> ans(n);
        vector<int> arr;
        for(int i=0; i<n; i++)
        {
            vector<int> vis(n, 0);
            arr.clear();

            dfs(i, adj, vis);

            // insert all visited nodes 
            for(int j = 0; j < n ; j++)
            {
                if(vis[j] && i != j) arr.push_back(j);
            }

            sort(arr.begin(), arr.end());
            ans[i] = arr;
        }
        return ans;

    }
};