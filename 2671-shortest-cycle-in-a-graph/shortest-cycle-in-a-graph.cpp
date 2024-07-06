class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];

        for(int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][1]].push_back(edges[i][0]);
            adj[edges[i][0]].push_back(edges[i][1]);
        }

        int ans = INT_MAX;
        for(int i=0; i < n; i++)
        {
            vector<int> distance(n, 100000);
            vector<int> parent(n, -1);

            queue<int> q;
            q.push(i);
            distance[i] = 0;

            while(!q.empty())
            {
                auto node = q.front();
                q.pop();

                for(auto adjnode : adj[node])
                {
                    if(distance[adjnode] == 100000)
                    {
                        distance[adjnode] = distance[node] + 1;
                        parent[adjnode] = node;
                        q.push(adjnode);
                    }
                    else  if(parent[adjnode] != node && parent[node] != adjnode)
                    {
                        //  cycle found
                        int cyclelen = distance[adjnode] + distance[node] + 1;
                        ans = min(ans,cyclelen);
                    }
                }
            }

        }

        if(ans == INT_MAX) return -1;
        return  ans;
    }
};