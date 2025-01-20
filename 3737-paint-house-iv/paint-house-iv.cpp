class Solution {
public:
    typedef long long ll;
    ll inf = 1e15;
    long long minCost(int n, vector<vector<int>>& cost) {
        ll dp[100005][3][3];
        ll ans = inf;

        for (ll i = 0; i < 3; i++)
        {
            for (ll j = 0; j < 3; j++)
            {
                if (i != j)
                {
                    dp[0][i][j] = cost[0][i] + cost[n - 1][j];
                }
                else
                {
                    dp[0][i][j] = inf;
                }
            }
        }

        for (ll i = 1; i < n / 2; i++)
        {
            for (ll j = 0; j < 3; j++)
            {
                for (ll k = 0; k < 3; k++)
                {
                    // DEBUG(i);
                    if (j == k)
                    {
                        dp[i][j][k] = inf;
                    }
                    else
                    {
                        dp[i][j][k] = inf;
                        for (ll nj = 0; nj < 3; nj++)
                        {
                            for (ll nk = 0; nk < 3; nk++)
                            {
                                if (nj != j && nk != k && nj != nk)
                                {
                                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][nj][nk]);
                                }
                            }
                        }
                        dp[i][j][k] += cost[i][j] + cost[n - i - 1][k];
                    }
                }
            }
        }
        ans = inf;
        for (ll i = 0; i < 3; i++)
        {
            for (ll j = 0; j < 3; j++)
            {
                ans = min(ans, dp[n / 2 - 1][i][j]);
            }
        }
        return ans;
    }
};