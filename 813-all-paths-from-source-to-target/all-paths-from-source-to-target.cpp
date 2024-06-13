class Solution {
public:
    void dfs(int node,int final, vector<int>&path, vector<vector<int>>& ans, vector<vector<int>>& graph)
    {
        path.push_back(node);
        if(node == final) ans.push_back(path);
        
        for(auto &it: graph[node])
        {
            dfs(it, final, path, ans, graph);
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        int n = graph.size();
        vector<int> path;

        dfs(0, n-1, path, ans, graph);
        return ans;
    }
};