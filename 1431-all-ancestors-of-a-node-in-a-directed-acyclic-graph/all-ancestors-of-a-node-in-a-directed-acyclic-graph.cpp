class Solution {
public:
    void visitchilds(int node,vector<int>& visitedchilds,vector<vector<int>>& adj )
    {
        visitedchilds[node] = 1;

        for(auto &it : adj[node])
        {
            if(!visitedchilds[it])
            {
                visitchilds(it, visitedchilds, adj);
            }
        }

    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }

        vector<vector<int>> ans(n);

        for(int par = 0; par < n; par++)
        {
            vector<int> visitedchilds(n, 0);

            visitchilds(par, visitedchilds, adj);

            for(int j = 0; j < n; j++)
            {
                if(visitedchilds[j] == 1 && j != par)
                {
                    ans[j].push_back(par);
                }
            }
        }

        return ans;
    }
};