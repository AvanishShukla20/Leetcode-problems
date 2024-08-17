class Solution {
public:
    int dfs(int node, vector<vector<int>>& adj, int& cnt, vector<int>& vis)
    {
        vis[node] = 1;
        unordered_set<int> st;
        int size = 1;
        for(auto &it : adj[node])
        {
            if(!vis[it])
            {
                int childsize = dfs(it, adj, cnt, vis);
                size += childsize;
                st.insert(childsize);
            } 
        }

        if(st.size() <= 1) cnt++;
        return size; 
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);

        for(int i = 0; i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(n, 0);
        int cnt = 0;
        dfs(0, adj, cnt, vis);
        return cnt;
    }
};