class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        
        int maxNode = 0;

        for(auto &edge : edges)
        {
            maxNode = max(maxNode, max(edge[0], edge[1]));
        }

        vector<int> indegree(maxNode + 1, 0);

        for(int i=0; i<edges.size(); i++)
        {
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
        }

        int ans;
        for(int i = 0; i < indegree.size(); i++)
        {
            if(indegree[i] == n)
            {
                ans = i;
                break;
            }
        }

        return ans;

    }
};