class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        vector<int> dp(n, 0);

        for(int i = 0; i<n; i++) dp[i] = matrix[0][i];

        for(int row = 1; row < n ; row++)
        {
            vector<int> curr(n, 0);
            for(int col = 0; col < n; col++)
            {
                int left = 1e9, right = 1e9;
                if(col > 0) left = dp[col-1];
                int up = dp[col];
                if(col+1 < n) right = dp[col+1];

                curr[col] = min(left, min(up, right)) + matrix[row][col];
            }
            dp = curr;  
        }

        int ans = 1e9;

        for(int j = 0; j < n; j++)
        {
            ans = min(ans, dp[j]);
        }
        return ans;
        
    }
};