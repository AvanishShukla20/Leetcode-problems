class Solution {
public:

    void dfs(int u, int& len, vector<int>&edges, vector<int>& vis, vector<bool>& isInCurrPath, vector<int>& dist)
    {
        if(u != -1){

        int v = edges[u];
        isInCurrPath[u] = true;
        vis[u] = 1;
        if(v != -1)
        {
            if(!vis[v])
            {
                dist[v] = dist[u] + 1;
                dfs(v, len, edges, vis, isInCurrPath, dist);
            }
            else if(isInCurrPath[v] == true)
            {
                // pakka cycle hai 
                len = max(len, dist[u] - dist[v] + 1);
            }

        }
        isInCurrPath[u] = false;

        }

    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        int ans = -1;
        vector<int> vis(n, 0);

        vector<bool> isInCurrPath(n, 0);
        vector<int> dist(n, 0);
        
        for(int i = 0; i < n;i++)
        {
            if(!vis[i])
            {
                int len = -1;
                dfs(i,len, edges, vis, isInCurrPath, dist);
                ans = max(ans, len);
            }
        }
        
        return ans;
    }
};