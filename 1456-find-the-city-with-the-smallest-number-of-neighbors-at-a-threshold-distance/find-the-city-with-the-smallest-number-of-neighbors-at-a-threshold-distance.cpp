class Solution {
public:

    void dijkstra(int src,vector<vector<pair<int,int>>>& adj,vector<int>& dist)
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

        pq.push({0,src});
        dist[src] = 0;

        while(!pq.empty())
        {
            auto temp = pq.top();
            pq.pop();

            int wgt = temp.first;
            int node = temp.second;

            for(auto it : adj[node])
            {
                int d = it.second, neighbour = it.first;

                if(wgt + d < dist[neighbour])
                {
                    dist[neighbour] = wgt + d;
                    pq.push({wgt+d, neighbour});
                }
            }
        }

    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //Why can't we do dikstra's algorithm here ->
        vector<vector<pair<int,int>>> adj(n);

        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u, wt});
        }

        int maxReach = INT_MAX;
        int ans = INT_MIN;
        for(int i=0; i < n; i++)
        {
            vector<int> dist(n,INT_MAX);
            dijkstra(i,adj, dist);

            int count = 0;

            for(int i=0; i < n; i++)
            {
                if(dist[i] <= distanceThreshold) count++;
            }

            if(count <= maxReach)
            {
                maxReach = count;
                ans = max(ans, i);
            }
        }

        return ans;
    }
};