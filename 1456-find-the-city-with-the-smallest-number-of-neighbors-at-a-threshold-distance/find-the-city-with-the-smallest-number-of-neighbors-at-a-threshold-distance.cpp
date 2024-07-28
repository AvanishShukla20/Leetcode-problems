class Solution {
public:
    void dijkstra(int src, int n, vector<vector<pair<int, int>>>& adj, vector<int>& distance)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({src, 0});
        distance[src] = 0;

        while(!pq.empty())
        {
            int node = pq.top().first;
            int dst = pq.top().second;
            pq.pop();

            for(auto &it : adj[node])
            {
                int neigh = it.first;
                int ds = it.second;
                if(dst + ds <= distance[neigh])
                {
                    distance[neigh] = dst + ds;
                    pq.push({neigh, dst + ds});
                } 
            }
        }

    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adj(n);

        for(int i = 0; i<edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }


        int ans = -1e9;
        int minFoundTillNow = 1e6;

        for(int i = 0; i < n; i++)
        {
            vector<int> distance(n, 1e9);
            
            dijkstra(i, n, adj,distance);
            cout<<"i : "<<i<<endl;
            int count = 0;

            for(int i = 0; i < distance.size(); i++)
            {
                cout<<distance[i]<<endl;
                if(distance[i] <= distanceThreshold)
                {
                    count++;
                }
            }

            
            if(count <= minFoundTillNow)
            {
                minFoundTillNow = count;
                ans = max(ans, i);
            }

        }

        return ans;
    }
};