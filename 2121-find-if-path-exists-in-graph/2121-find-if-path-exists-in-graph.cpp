class Solution {
public:
    int find(int a, vector<int>& parent)
    {
        if(parent[a] == a) return a;

        return parent[a] = find(parent[a], parent);
    }

    void Union(int a, int b, vector<int>& parent, vector<int>& rank)
    {
        int par_a = find(a,parent);
        int par_b = find(b, parent);

        if(par_a == par_b) return;

        if(rank[par_a] < rank[par_b])
        {
            parent[par_a] = par_b;
        }
        else if(rank[par_a] > par_b)
        {
            parent[par_b] = par_a;
        }
        else
        {
            parent[par_b] = par_a;
            rank[par_a] += 1;
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        

        vector<int> parent(n), rank(n, 0);

        for(int i = 0; i < n ; i++)
        {
            parent[i] = i;
        }

        for(int i=0; i < edges.size(); i++)
        {
            Union(edges[i][0], edges[i][1], parent, rank);
        }

        return (find(source, parent) == find(destination, parent));
    }
};