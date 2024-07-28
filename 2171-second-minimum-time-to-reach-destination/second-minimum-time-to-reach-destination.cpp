class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int, vector<int>> adj;

        for(int i = 0; i<edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);

        }

        vector<int> min_time(n + 1, 1e9);
        vector<int> sec_min_time(n + 1, 1e9);

        min_time[1] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, 1}); // 1 is src and 0 is start time

        while(!pq.empty())
        {
            auto tuple = pq.top();
            int timepassed = tuple.first;
            int node = tuple.second;
            pq.pop();

            if(node == n && sec_min_time[node] != 1e9)
            {
                return sec_min_time[node];
            }

            // check for green(div is even) or red(div is odd)
            int div = timepassed / change;
            if(div%2 != 0) timepassed = change * (div + 1);

            for(auto &it : adj[node])
            {
                int steps = timepassed + time;
                if(steps < min_time[it])
                {
                    sec_min_time[it] = min_time[it];
                    min_time[it] = steps; 
                    pq.push({steps, it});
                }
                else if(steps < sec_min_time[it] && steps != min_time[it]) // second condition is applied to handle {2, 2, 4} like case
                {
                    sec_min_time[it] = steps;
                    pq.push({steps, it});
                }
            }
        }

        return -1; 

    }
};