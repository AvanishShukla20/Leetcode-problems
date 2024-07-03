class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> adj(n+1);

        for(int  i = 1; i < n; i++)
        {
            adj[i].push_back(i+1);
            adj[i+1].push_back(i);
        }

        if(x != y)
        {
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        vector<vector<int>> storeAns;   
        for(int src = 1; src <= n; src++)
        {
            vector<int> distance(n + 1, 1e9); 
            distance[src] = 0;
            priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
            pq.push({0, src});

            while(!pq.empty())
            {
                auto top = pq.top();
                pq.pop();

                int dist = top.first;
                int node = top.second;

                for(auto &it : adj[node])
                {
                    int newdst = dist + 1;
                    if(newdst < distance[it])
                    {
                        distance[it] = newdst;
                        pq.push({newdst, it});
                    }
                }
            }

            storeAns.push_back(distance);
        }


        vector<int> ans(n);
        for(int k = 1; k<=n; k++)
        {
            int cnt = 0;
            for(auto &it : storeAns)
            {
                for(auto el : it)
                {
                    if(el == k) cnt++;
                }
            }
            ans[k-1] = cnt;
        }
        return ans;
    }
};