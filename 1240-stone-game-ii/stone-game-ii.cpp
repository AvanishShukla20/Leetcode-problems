class Solution {
public:
    // t == 1 then alice otherwise bob turn
    int solve(int i,int m, int turn, vector<int>& piles,vector<vector<vector<int>>>& dp)
    {
        if(i >= piles.size()) return 0;
        if(dp[i][m][turn] != -1) return dp[i][m][turn];


        int stones = 0, result;

        if(turn == 1) result = -1; // as in turn 1 i have to return max
        else result = 1e9;

        for(int x = 1; x <= 2*m; x++)
        {
            //using prefix sum concept we add possible stones of piles selected consecutively
            if(i+x-1 < piles.size()) stones += piles[i+x-1]; // x = 1, 2, 3 ...corresponding i+x-1 = i, i+1, i+2, i+3...

            if(turn == 1) // alice turn 
            {
                int pos = stones + solve(i+x, max(x, m), 0, piles, dp);
                // return best from yours
                result = max(pos, result);
            }
            else
            {
                int pos2 = 0 + solve(i+x, max(x, m), 1, piles, dp);
                // return worst from opponent
                result = min(result, pos2);
            }

        }
        return dp[i][m][turn] = result;

    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (n+1, vector<int> (2, -1)));

        return solve(0, 1, 1, piles, dp);
    }
};