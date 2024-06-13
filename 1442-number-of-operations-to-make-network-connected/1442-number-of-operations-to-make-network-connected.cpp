class Solution {
public:
    void Union(int a, int b, vector<int>& parent)
    {
        int par_a = findParent(a, parent);
        int par_b = findParent(b, parent);
        parent[par_a] = par_b;

    }
    int findParent(int node, vector<int>& parent)
    {
        if(parent[node] == node) return node;

        return parent[node] = findParent(parent[node], parent);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n -1) return -1;
        //it is not needed that you follow Union by rank every time to apply DSU
        vector<int> parent(n);

        for(int i=0; i<n;i++)
        {
            parent[i] = i;
        }

        for(int i=0; i < connections.size();i++)
        {
            Union(connections[i][0], connections[i][1], parent);
        }

        int prime_parents = 0;
        for(int i = 0; i< parent.size(); i++)
        {
            if(parent[i] == i) prime_parents++; 
        }

        return prime_parents-1 ;


    }
};