class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));

        for(int i = 0; i<n; i++) dp[0][i] = matrix[0][i];

        for(int row = 1; row < n ; row++)
        {
            for(int col = 0; col < n; col++)
            {
                int left = 1e9, right = 1e9;
                if(col > 0) left = dp[row-1][col-1];
                int up = dp[row-1][col];
                if(col+1 < n) right = dp[row-1][col+1];
                dp[row][col] = min(left, min(up, right)) + matrix[row][col];
            }  
        }

        int ans = 1e9;

        for(int j = 0; j < n; j++)
        {
            ans = min(ans, dp[n-1][j]);
        }
        return ans;
        
    }
};