class Solution {
public:
    bool solve(int i, int j, int bracecnt , vector<vector<char>>& grid, vector<vector<vector<int>>>& dp)
    {
        int m=grid.size(), n=grid[0].size();
        if(i>=m || j >= n) return false;
        
        // preprocess the things to be done and pre return if invalid case found
        char ch = grid[i][j];
        if(ch == ')') bracecnt--;
        else bracecnt++;

        if(bracecnt < 0) return false;

        //now check for i == m-1 and j == n-1
        if(i == m-1 && j == n-1)
        {
            return (bracecnt == 0);
        }

        if(dp[i][j][bracecnt] != -1) return dp[i][j][bracecnt];

        bool res = solve(i, j+1,bracecnt, grid, dp) || solve(i+1, j, bracecnt, grid, dp);
        return dp[i][j][bracecnt] = res;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int m=grid.size(), n= grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (203, -1)));
        return solve(0, 0, 0, grid, dp);
    }
};