class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        /* Here we have to find all the nodes with sum along the path under threshold for 
           all  the nodes. So , we will need the minpathSum for each and every node to ther node. So, We use floyd algorithm*/

           vector<vector<int>> costMatrix(n, vector<int> (n, 1e9));

           for(int i=0; i<edges.size(); i++)
           { 
                int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
                //sice city connections are mostly undirected graphs. So, 
                costMatrix[u][v] = wt;
                costMatrix[v][u] = wt;  
           }

           for(int i=0; i<n; i++){
                costMatrix[i][i] = 0;
           }




           //algorithm

           for(int intermediate = 0; intermediate < n; intermediate++)
           {
            for(int i=0; i<n; i++)
            {
                for(int j = 0; j < n ; j++)
                {
                    costMatrix[i][j] = min(costMatrix[i][j], costMatrix[i][intermediate] + costMatrix[intermediate][j]);
                }
            }
           }



           int minCount = 1e9, ans= -1;

           for(int city = 0; city < n; city++)
           {
            int count = 0;
            for(int neighbour = 0; neighbour < n; neighbour++)
            {
                if(costMatrix[city][neighbour] <= distanceThreshold) count++;
            }

            if(count <= minCount)
            {
                minCount = count;
                ans = city;
            }
           }

        return ans;
    }
};