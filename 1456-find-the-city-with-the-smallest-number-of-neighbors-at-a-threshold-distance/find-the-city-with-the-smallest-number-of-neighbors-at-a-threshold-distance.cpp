class Solution {
public:
    #define P pair<int, int> 
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<P>> adj(n);

        for(int i=0; i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        int ans = -1e9;
        int mincnt = 1e9;

        for(int i=0; i<n; i++)
        {
            int start = i;
            vector<int> dist(n, 1e9);
            dist[i] = 0;
            priority_queue<P, vector<P>, greater<P>> pq;
            pq.push({0, i});

            while(!pq.empty())
            {
                auto t = pq.top();
                pq.pop();
                int node = t.second;
                int d = t.first;

                for(auto &it : adj[node])
                {
                    int adjnode = it.first;
                    int dis = it.second;

                    if(d+dis <= dist[adjnode])
                    {
                        dist[adjnode] = d+dis;
                        pq.push({dist[adjnode], adjnode});
                    }
                }
            }

            int cnt = 0;
            cout<<start<<endl;

            for(int i=0; i<dist.size(); i++)
            {
                cout<<" "<<i<<" -> "<<dist[i];
                if(i != start && dist[i]<=distanceThreshold) cnt++;
            }
            
            if(cnt <= mincnt)
            {
                mincnt = cnt;
                ans = start;
            }
            
        }
        
        return ans;
    }
};