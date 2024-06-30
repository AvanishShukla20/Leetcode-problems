class Solution {
public:
    void topoSort(vector<vector<int>>& adj, vector<int>& indegree,vector<int>& topoOrder)
    {   
        queue<int> q;
        for(int i = 0; i < indegree.size(); i++)
        {
            if(indegree[i] == 0) q.push(i);
        }
        
        while(!q.empty())
        {
            auto node = q.front();
            topoOrder.push_back(node);
            q.pop();

            for(auto &it: adj[node])
            {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n);

        for(int i=0; i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }

        for(int i =0; i<edges.size(); i++)
        {
            indegree[edges[i][1]]++;
        }

        vector<int> topoOrder;
        topoSort(adj, indegree, topoOrder);

        vector<set<int>> vec(n); // set is taken to store unique elements

        for(int i=0; i<topoOrder.size(); i++)
        {
            int node = topoOrder[i];
            cout<<topoOrder[i]<<" ";
            for(auto &it : adj[node])
            {
                vec[it].insert(node);
                // inserting the ancestors of node if they are present

                vec[it].insert(vec[node].begin(), vec[node].end());
            }
        }

        vector<vector<int>>  result(n);

        for(int i =0; i < n; i++)
        {
            result[i] = vector<int> (vec[i].begin(), vec[i].end());
        }

        return result;

    }
};