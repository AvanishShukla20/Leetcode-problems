class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        vector<int> vis(n, 0);

        vector<int> ans;

        for(int i=0; i<edges.size(); i++)
        {
            vis[edges[i][1]] = 1;
        }

        for(int i = 0; i < n; i++)
        {
            if(!vis[i]) ans.push_back(i);
        }
        return ans;
    }
};