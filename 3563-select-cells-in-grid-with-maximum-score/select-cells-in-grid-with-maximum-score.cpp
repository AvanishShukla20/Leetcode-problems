class Solution {
public:
    int solve(int r,int n,int mask, vector<int>& nums,unordered_map<int, vector<int>>& mpp, vector<vector<int>>& dp)
    {

            if(r == n) return 0;
            // in solve function we iterate on nums array and maximise the sum by selected greatest and valid elements first
            if(dp[r][mask] != -1) return dp[r][mask];

            int maxi = 0;

            int el = nums[r];
            for(auto &optionr : mpp[el])
            {
                //using masking concept
                if((mask&(1 << optionr)) == 0)
                {
                    // i can choose this row
                    maxi = max(maxi, el + solve(r+1, n, (mask | (1<<optionr)), nums,mpp, dp));
                }
            }

            maxi = max(maxi, solve(r+1, n, mask, nums,mpp, dp));
            return dp[r][mask] = maxi;
    }
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        unordered_set<int> st;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                
                st.insert(grid[i][j]);
            }
        }

        vector<int> storedEl;
        for(auto &it : st)
        {
            storedEl.push_back(it);
        }

        // sort in decreasing order

        sort(storedEl.rbegin(), storedEl.rend());

        unordered_map<int, vector<int>> mpp;
        // map stores what rows contain each element(key)
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                mpp[grid[i][j]].push_back(i);
            }
        }
        int mask = 0;
        vector<vector<int>> dp(101, vector<int> (2001,-1));  // as mask can max go to 2^10 approx 1025 and size of storedEl is max 100
        return solve(0,storedEl.size(),mask, storedEl, mpp, dp);
    }
};