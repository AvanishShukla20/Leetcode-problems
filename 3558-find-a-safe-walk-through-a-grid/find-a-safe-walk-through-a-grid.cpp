class Solution {
public:
    #define P pair<int, pair<int, int>> 
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        //dijkstra
        int m = grid.size(), n= grid[0].size();
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>> dist(m, vector<int> (n, 1e4));

        pq.push({grid[0][0], {0, 0}});
        vector<vector<int>> traversevec = {{0,1},{1,0},{0,-1},{-1,0}};
        while(!pq.empty())
        {
            auto p = pq.top();
            pq.pop();
            int d = p.first;
            int r = p.second.first;
            int c = p.second.second;

            for(int i=0; i<traversevec.size(); i++)
            {
                int nr = traversevec[i][0] + r;
                int nc = traversevec[i][1] + c;

                if(nr>=0&&nr<m&&nc>=0&&nc<n&& dist[nr][nc] > d + grid[nr][nc])
                {
                    dist[nr][nc] = d + grid[nr][nc];
                    pq.push({d+grid[nr][nc], {nr, nc}});
                }
            }
        }

        cout<<dist[m-1][n-1]<<endl;
        if(dist[m-1][n-1] + 1 <= health) return true;
        return false;
    }
};