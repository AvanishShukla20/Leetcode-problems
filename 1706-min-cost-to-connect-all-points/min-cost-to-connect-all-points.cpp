class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<pair<int,int>>> adj(points.size());
        int u, v, wt;
        // indexes ko hi node maan lenge hm idhar 
        for(int i = 0; i < points.size(); i++)
        {
            for(int j = i + 1; j < points.size(); j++)
            {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                wt = abs(x1 - x2) + abs(y1 - y2);
                adj[i].push_back({j, wt});
                adj[j].push_back({i, wt});
            }
            
        }



        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        vector<int> vis(points.size(), 0);

        pq.push({0, 0});
        int sum  = 0;

        while(!pq.empty())
        {
            auto fpair = pq.top();
            pq.pop();
            int edgwt = fpair.first;
            int node = fpair.second;

            // most important that you were missing
            if(vis[node]) continue;

            vis[node] = 1;
            cout<<" node : "<<node<<" -> ";
            cout<<"edge weight : "<<edgwt<<endl;

            sum += edgwt;

            for(auto &it : adj[node])
            {
                int neighbour = it.first;
                int wght = it.second;

                if(!vis[neighbour])
                {
                    pq.push({wght, neighbour});
                }
            }
        }

        return sum;

    }
};