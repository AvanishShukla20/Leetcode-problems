class DisjointSet
{
    public:
    vector<int> parent, size;
    DisjointSet(int n)
    {
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i = 0; i<= n; i++) parent[i] = i;
    }

    int find(int a)
    {
        if(parent[a] == a) return a;

        return parent[a] = find(parent[a]);
    }

    void Union(int a, int b)
    {
        int ulpa = find(a);
        int ulpb = find(b);

        if(ulpa == ulpb) return;

        if(size[ulpa] < size[ulpb])
        {
            parent[ulpb] = ulpa;
            size[ulpb] += size[ulpa];
        }
        else
        {
            parent[ulpa] = ulpb;
            size[ulpa] += size[ulpb];
        }
    }
};

 
class Solution {
public:
    void bfs(int& ir, int& ic, vector<vector<char>>& grid, vector<vector<int>>& vis)
    {
        vis[ir][ic] = 1;
        int m = grid.size(),n = grid[0].size();

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, -1, 0, 1};

        queue<pair<int, int>> q;
        q.push({ir, ic});

        while(!q.empty())
        {
            auto tuple = q.front();
            q.pop();
            int i = tuple.first;
            int j = tuple.second;

            for(int c = 0; c < 4; c++)
            {
                int drow = i + dr[c];
                int dcol = j + dc[c];

                if(drow >= 0 && drow < m && dcol >= 0 && dcol < n && grid[drow][dcol] == '1' && !vis[drow][dcol])
                {
                    vis[drow][dcol] = 1;
                    q.push({drow, dcol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int cnt = 0;
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    bfs(i,j, grid, vis);
                    cnt += 1;
                }
            }
            
        }

        return cnt;
    }
};