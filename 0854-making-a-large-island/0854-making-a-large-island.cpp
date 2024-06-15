class DisjointSet{
    vector<int> parent;
    public :
    vector<int> size;
    DisjointSet(int n)
    {  
         parent.resize(n+1);
        size.resize(n+1);
        for(int i=0; i<=n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUlPar(int node)
    {
        if(parent[node] == node) return node;

        return parent[node] = findUlPar(parent[node]);
    }
    void UnionBySize(int a, int b)
    {
        int ulpa = findUlPar(a);
        int ulpb = findUlPar(b);

        if(ulpa == ulpb) return;

        if(size[ulpa] < size[ulpb])
        {
            parent[ulpa] = ulpb;
            size[ulpb] += size[ulpa];
        }
        else
        {
            parent[ulpb] = ulpa;
            size[ulpa] += size[ulpb];
        }
    }

};



class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);

        int drow[4] = {0, -1, 1, 0};
        int dcol[4] = {-1, 0, 0, 1};


        for(int row = 0; row < n; row++)
        {
            for(int col = 0; col < n ; col++)
            {
                if(grid[row][col] == 0) continue;

                for(int i=0; i<4; i++)
                {
                    int adjrow = row + drow[i];
                    int adjcol = col + dcol[i];

                    if(adjrow < n && adjrow >= 0 && adjcol < n && adjcol >= 0 && grid[adjrow][adjcol] == 1)
                    {
                        int currNo = row * n + col;
                        int adjNo = adjrow * n + adjcol;
                        ds.UnionBySize(currNo, adjNo);
                    }
                }
            }
        }

        int result = 1;

        for(int row = 0; row < n; row++)
        {
            for(int col = 0; col < n; col++)
            {
                if(grid[row][col] == 1) continue;
                else
                {
                    set<int> UltparentComponents;
                   for(int i=0; i<4; i++)
                    {
                        int adjrow = row + drow[i];
                        int adjcol = col + dcol[i];

                        if(adjrow < n && adjrow >= 0 && adjcol < n && adjcol >= 0 && grid[adjrow][adjcol] == 1)
                        {
                            int adjNo = adjrow * n + adjcol;
                            int par = ds.findUlPar(adjNo);
                            // we will necessarily have to use a set so that connected components of same ult parent does not contribute more than once in answer
                            UltparentComponents.insert(par); 
                        }
                    }

                    int totalComponentSize= 0;
                    for(auto it : UltparentComponents)
                    {
                        totalComponentSize += ds.size[it];
                    }
                    totalComponentSize += 1;

                    result = max(result, totalComponentSize);
                }
            }
        }




        //if all are 1's in grid then the ultimate parent of all will be same . Hence->

        for(int no = 0; no < n*n; no++)
        {
            result = max(result, ds.size[ds.findUlPar(no)]);
        }
        return result;
    }
};