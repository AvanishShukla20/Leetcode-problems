class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        cuts.push_back(n); // pushing initial stick len in last
        cuts.insert(cuts.begin(), 0); // pushing 0 in the front

        vector<vector<int>> dp(m + 2, vector<int> (m+2, 0));
        
        // MUST sort the array so as the sub - problems can be independently solved
        sort(cuts.begin(), cuts.end());

        for(int i = m; i>= 1; i--)
        {
            for(int j = i; j <= m; j++)
            {
                int mini = 1e9;
                for(int k = i; k <= j; k++)
                {
                    int cost = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][m];
    }
};