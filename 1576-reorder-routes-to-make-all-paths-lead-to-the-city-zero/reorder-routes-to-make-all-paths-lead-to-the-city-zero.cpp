class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {

        set<vector<int>> st(connections.begin(), connections.end());
        vector<vector<int>> adj(n);
        
        for(int i=0;i<connections.size(); i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        int ans = 0;
        queue<int> q;
        vector<int> vis(n, 0);
        vis[0] = 1;
        q.push(0);
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            vis[node] = 1;

            for(auto &it : adj[node])
            {
                if(!vis[it])
                {
                    if(st.find({node, it}) != st.end()) ans++;
                    q.push(it);
                }
            }
        }

        return ans;
    }
};