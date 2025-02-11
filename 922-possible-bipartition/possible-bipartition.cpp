class Solution {
public:
    bool dfs(int node,int color, vector<int>& colored, unordered_map<int, vector<int>>& adj)
    {
        colored[node] = color;
        int nextcolor;

        if(color == 1) nextcolor = -1;
        else nextcolor = 1;

        for(auto &adjnode : adj[node])
        {
            if(colored[adjnode] == 0)
            {
                if(dfs(adjnode, nextcolor, colored, adj) == false) return false;
            }
            else if(colored[adjnode] == color)
            {
                cout<<node<<endl;
                return false;
            }
        }

        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> adj;

        for(int i=0; i<dislikes.size(); i++)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }

        vector<int> colored(n+1, 0);

        for(int val = 1; val<=n; val++)
        {
            if(colored[val] == 0)
            {
                if(dfs(val, 1, colored, adj) == false) return false;
            }
        }

        return true;
    }
};