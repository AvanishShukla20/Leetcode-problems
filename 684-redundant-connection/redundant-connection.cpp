class DisJointSet{
    public :
    vector<int> parent,rank;
    DisJointSet(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0; i < n; i++) parent[i] = i;
    }

    int find(int node)
    {
        if(node == parent[node]) return node;

        return parent[node] = find(parent[node]);
    }
    void Union(int a, int b)
    {
        int ulpa = find(a);
        int ulpb = find(b);

        if(rank[ulpa] < rank[ulpb])
        {
            parent[ulpa] = ulpb;
        }
        else if(rank[ulpa] > rank[ulpb])
        {
            parent[ulpb] = ulpa;
        }
        else
        {
            parent[ulpa] = ulpb;
            rank[ulpb] += 1;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisJointSet ds(edges.size() + 1);
        set<int> nodeconnected;
        vector<vector<int>> ans;
        for(auto &it : edges)
        {
            int a = it[0], b = it[1];
            int par_a = ds.find(a);
            int par_b = ds.find(b);

            if(par_a == par_b) ans.push_back({a, b});
            else ds.Union(a, b);
        }
        
        return ans.back();
    }
};