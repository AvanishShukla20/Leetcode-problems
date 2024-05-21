class Solution {
public:
    void dfs(int node,vector<int>& v,vector<vector<int>>& isConnected)
    {
        v[node] = 1;
        for(int i = 0; i<isConnected.size(); i++)
        {
            if(isConnected[node][i] == 1 && v[i] == 0) dfs(i,v,isConnected);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> v(n, 0);
        int count = 0;
        for(int i= 0; i<n; i++)
        {
            if(v[i] == 0)
            {
                count++;
                dfs(i, v, isConnected);
            }
        }
        return count;
    }
};