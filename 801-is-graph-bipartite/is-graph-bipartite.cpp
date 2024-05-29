class Solution {
public:

    bool solve (int start,vector<vector<int>>& graph, vector<int>& colors)
    {
        int n = graph.size();
        queue<int> Q;
        Q.push(start);
        colors[start] = 0;

        while(!Q.empty())
        {
            int frontNode = Q.front();
            Q.pop();

            for(auto it : graph[frontNode]){
                if(colors[it] == -1)
                {
                    colors[it] = !colors[frontNode];
                    Q.push(it);
                }
                else if(colors[it] == colors[frontNode]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);
        for(int i=0; i< n; i++)
        {
            if(colors[i] == -1)
            {
                if(solve(i, graph, colors) == false) return false;
            }
        }

        return true;
    }
};