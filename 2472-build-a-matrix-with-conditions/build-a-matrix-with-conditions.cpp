class Solution {
public:
    void toposort(int node, vector<vector<int>>& adj, stack<int>& st, vector<int>& vis, vector<bool>& inRecursion, bool& isSafe)
    {
        vis[node] = 1;
        inRecursion[node] = true;
        for(auto &it : adj[node])
        {
            if(!vis[it])
            {
                toposort(it, adj, st, vis, inRecursion, isSafe);
            }
            else if(inRecursion[it] == true)
            {
                isSafe = false;
            }
        }

        inRecursion[node] = false;
        st.push(node);
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> rowadj(k + 1);
        vector<vector<int>> coladj(k + 1);
        
        for(int i =0; i < rowConditions.size(); i++)
        {
            rowadj[rowConditions[i][0]].push_back(rowConditions[i][1]);
        }

        for(int i =0; i < colConditions.size(); i++)
        {
            coladj[colConditions[i][0]].push_back(colConditions[i][1]);
        }

        vector<int> vis1(k + 1, 0);
        vector<int> vis2(k + 1, 0);

        vector<bool> inRecursion1(k+1, false), inRecursion2(k+1, false);

        bool isSafe = true;
        stack<int> st1, st2;

        for(int i = 1;i<= k; i++)
        {
            if(!vis1[i])
            {
                toposort(i, rowadj, st1, vis1, inRecursion1, isSafe);
                if(isSafe == false) return {};
            }
        }     

        for(int i = 1; i<= k; i++)
        {
            if(!vis2[i])
            {
                toposort(i, coladj, st2, vis2, inRecursion2, isSafe);
                if(isSafe == false) return {};
            }
        } 

        vector<vector<int>> grid(k, vector<int> (k, 0));

        int p = 0, q = 0;

        unordered_map<int, pair<int, int>> mpp;

        while(!st1.empty() && p < k)
        {
            mpp[st1.top()].first = p;
            st1.pop();
            p++;
        }

        while(!st2.empty() && q < k)
        {
            mpp[st2.top()].second = q;
            st2.pop();
            q++;
        }


        for(int i = 1; i <= k; i++)
        {
            grid[mpp[i].first][mpp[i].second] = i;
        }

        return grid;
    }
};