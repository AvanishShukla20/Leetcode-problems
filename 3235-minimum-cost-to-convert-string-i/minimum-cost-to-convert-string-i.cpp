class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = original.size();
        vector<vector<pair<int, int>>> adj(26);

        for(int i = 0; i < n; i++)
        {
            int ds = changed[i] - 'a';
            int cst  = cost[i];
            adj[original[i]-'a'].push_back({cst, ds});
        }

        //floyd warshall algorithm ->

        vector<vector<int>> grid(26, vector<int> (26, 1e9));

        for(int i = 0; i<adj.size(); i++)
        {
            int s = i;
            for(auto &it : adj[i])
            {
                int cs = it.first;
                int ds = it.second;

                grid[s][ds] = min(grid[s][ds], cs);
            }
            
        }

        for(int i =0; i<grid.size(); i++)
        {
            grid[i][i] = 0;
        }

        for(int via = 0; via < 26; via++)
        {
            for(int src = 0; src < 26; src++)
            {
                for(int dest = 0; dest < 26; dest++)
                {
                    int getcost = grid[src][via] + grid[via][dest];
                    if(getcost <= grid[src][dest])
                    {
                        grid[src][dest] = getcost;
                    }
                }
            }
        }

        //now matrix prepared
        long long ans = 0;

        for(int i = 0; i<source.size(); i++)
        {
            if(source[i] != target[i])
            {
                if(grid[source[i] - 'a'][target[i] - 'a'] >= 1e9) return -1;
                ans += grid[source[i] - 'a'][target[i] - 'a'];
            }
        }

        return ans;


    }
};