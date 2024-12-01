class Solution {
public:
    void dfs(int node,vector<int>& path, unordered_map<int, vector<int>>& adj)
    {
        while(!adj[node].empty())
        {
            int neighbour = adj[node].back();
            adj[node].pop_back();
            dfs(neighbour,path, adj);
        }
        path.push_back(node);
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int n = pairs.size();
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> indegree;
        unordered_map<int, int> outdegree;
        for(int i=0; i<n; i++)
        {
            adj[pairs[i][0]].push_back(pairs[i][1]);
            indegree[pairs[i][1]]++;
            outdegree[pairs[i][0]]++;
        }

        int startNode = pairs[0][0];
        for(auto &it : adj)
        {
            int node = it.first;
            if(outdegree[node]-indegree[node] == 1)
            {
                startNode = node;
                break;
            }
        }

        vector<int> path;
        dfs(startNode,path, adj);
        reverse(path.begin(), path.end());
        for(int i=0; i<path.size(); i++)
        {
            cout<<path[i]<<" ";
        }
        vector<vector<int>> ans;
        for(int i=0; i<n; i++)
        {
            ans.push_back({path[i], path[i+1]});
        }
        return ans;
    }
};