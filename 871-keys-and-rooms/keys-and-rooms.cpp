class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<vector<int>> adj(n);

        for(int  i=0; i<rooms.size(); i++)
        {
            for(int j =0; j < rooms[i].size(); j++)
            {
                adj[i].push_back(rooms[i][j]);
            }    
        }

        vector<int> vis(n, 0);

        queue<int> q;

        q.push(0);
        vis[0] = 1;

        while(!q.empty())
        {
            auto room = q.front();
            q.pop();
            vis[room] = 1;

            for(auto &it : adj[room])
            {
                if(!vis[it])
                {
                    q.push(it);
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(!vis[i]) return false;
        }
        return true;
    }
};