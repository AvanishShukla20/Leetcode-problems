class Solution {
public:
    const int MOD = 1e9 + 7;

    int memo[31][1001];

    int solve(int n, int k, int target)
    { 
        if(target < 0) return 0;
        if(n == 0) return target == 0;

        if(memo[n][target] != -1) return memo[n][target];

        int ways = 0;
        for(int face = 1; face <= k; face++)
        {
            ways = (ways + solve(n-1,k, target - face)) % MOD;
        }

        memo[n][target] = ways;

        return ways;

    }
    int numRollsToTarget(int n, int k, int target) {

        /* initialing memo 2D array */
        memset(memo, -1, sizeof(memo));

        return solve(n,k,target);
    }
};