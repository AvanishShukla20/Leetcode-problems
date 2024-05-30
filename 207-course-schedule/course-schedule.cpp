class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> indegree(n);

        for(auto& it : prerequisites)
        {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        
        queue<int> Q;
        for(int i=0; i< n; i++)
        {
            if(indegree[i] == 0) Q.push(i);
        }

        vector<int> ans;
        while(!Q.empty())
        {
            int frontV = Q.front();
            Q.pop();
            ans.push_back(frontV);
            for(int& it : adj[frontV])
            {
                indegree[it]--;
                if(indegree[it] == 0) Q.push(it);
            }
        }

        return ans.size() == n;


    }
};