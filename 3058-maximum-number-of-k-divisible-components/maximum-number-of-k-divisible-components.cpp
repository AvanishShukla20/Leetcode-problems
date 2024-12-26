class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        if(n == 1) return 1;
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> indegree(n, 0); // used to represent that if an edge is removed from a node or not

        //we need another vector to store updated values of each node for further use
        vector<long long> nodevalues(n);
        for(int i=0;i<values.size(); i++)
        {
            nodevalues[i] = values[i];
        }

        for(auto &it : edges)
        {
            indegree[it[1]]++;
            indegree[it[0]]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i] == 1) q.push(i);
        }

        int ans =0;

        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            long long val = nodevalues[node];
            if(val%k == 0) ans++;
            indegree[node]--;

            for(auto &neighbour : adj[node])
            {
                if(indegree[neighbour] > 0)
                {
                    indegree[neighbour]--;
                    if(val%k != 0) nodevalues[neighbour] += val; // if we can't form a valid component then add node's value to its adjacents 
                    if(indegree[neighbour] == 1)
                    {
                        //it became a leaf candidate so push it in queue
                        q.push(neighbour);
                    }

                }
            }
        }

        return ans;
    }
};