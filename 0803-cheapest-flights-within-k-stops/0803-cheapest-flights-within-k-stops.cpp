class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        
       priority_queue<pair<int,pair<int, int>>,  vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int, int>>>> pq;

       vector<int> distance(n, 1e9);

       vector<vector<pair<int,int>>> adj(n);

       for(int i=0; i<flights.size() ;i++)
       {
            int u = flights[i][0];
            int v = flights[i][1];
            int dst = flights[i][2];

            adj[u].push_back({v, dst});

       }

       pq.push({0,{src, 0}});
       distance[src] = 0;

       while(!pq.empty())
       {
        auto nodepair = pq.top();
        // we will have stops as the first priority here !!

        int stops = nodepair.first;
        int node = nodepair.second.first;
        int cost = nodepair.second.second;
        pq.pop();

        if(stops > k) continue;

        for(auto it : adj[node])
        {
            int adjnode = it.first;
            int edgWt = it.second;

            if(cost + edgWt < distance[adjnode] && stops <= k)
            {
                distance[adjnode] = cost + edgWt;
                pq.push({stops + 1, {adjnode, cost + edgWt}});
            }
            
        }
       }

        if(distance[dst] == 1e9) return -1;
        return distance[dst];

    }
};