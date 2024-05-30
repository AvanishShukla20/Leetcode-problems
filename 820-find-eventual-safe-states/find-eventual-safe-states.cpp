class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>&pathcovered, vector<int>& check)
    {
        vis[node] = 1;
        pathcovered[node] = 1;

        for(auto it : graph[node])
        {
            if(!vis[it])
            {
                if(dfs(it, graph, vis, pathcovered, check) == true)
                {
                    check[node] = 0;
                    return true;
                }
            }
            else if(pathcovered[it] == 1)
            {
                check[node] = 0;
                return true;
            }
        }

        check[node] = 1;
        pathcovered[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int> vis(n,0);
        vector<int> pathcovered(n, 0);
        vector<int> ans;
        vector<int> check(n, 0);
        for(int i =0; i<n ; i++)
        {
            if(!vis[i])
            {
                dfs(i, graph, vis, pathcovered, check);
            }
        }
        for(int i = 0; i<n ; i++)
        {
            if(check[i])
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};