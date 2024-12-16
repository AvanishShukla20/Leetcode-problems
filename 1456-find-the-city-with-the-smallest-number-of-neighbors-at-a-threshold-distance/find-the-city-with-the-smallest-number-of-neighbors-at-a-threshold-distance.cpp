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

        priority_queue<P, vector<P>, greater<P>> pq1;

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
            
            cout<<endl;
            pq1.push({cnt, start});
            
        }

        
        int ans = 1000;
        int md = 1e9;
        while(!pq1.empty())
        {
            auto p = pq1.top();
            pq1.pop();
            if(ans == 1000)
            {
                ans = p.second;
                md = p.first;
            }
            else if(md == p.first)
            {
                ans = p.second;
            }
            else break;
        }
        
        return ans;
    }
};