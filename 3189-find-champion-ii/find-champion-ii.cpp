class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);

        for(auto &it : edges)
        {
            indegree[it[1]]++;
        }
        int inCount = 0, res;
        
        for(int i =0; i<n; i++)
        {
            if(indegree[i] == 0)
            {
                if(inCount < 1) res = i;
                inCount++;
            }
        }

        if(inCount > 1) return -1;
        return res;
    }
};