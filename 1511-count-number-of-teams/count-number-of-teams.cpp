class Solution {
public:
    int solveIncreasing(int idx, int size, vector<int>& rating, vector<vector<int>>& dpInc)
    {
        int n = rating.size();
        if(size == 3) return 1;
        if(idx >= n) return 0;

        if(dpInc[idx][size] != -1) return dpInc[idx][size];

        int count = 0;
        for(int choice = idx + 1; choice < n; choice++)
        {
            if(rating[choice] > rating[idx])
            {
                count += solveIncreasing(choice, size+1, rating, dpInc);
            }
        }

        return dpInc[idx][size] = count;
    }
    int solveDecreasing(int idx, int size, vector<int>& rating, vector<vector<int>>& dpDec)
    {
        int n = rating.size();
        if(size == 3) return 1;
        if(idx >= n) return 0;

        if(dpDec[idx][size] != -1) return dpDec[idx][size];

        int count = 0;
        for(int choice = idx + 1; choice < n; choice++)
        {
            if(rating[choice] < rating[idx])
            {
                count += solveDecreasing(choice, size+1, rating, dpDec);
            }
        }

        return dpDec[idx][size] = count;
    }

    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;
        vector<vector<int>> dpInc(n, vector<int> (4, -1));
        vector<vector<int>> dpDec(n, vector<int> (4, -1));
        for(int i = 0; i<n; i++)
        {
            ans += solveIncreasing(i, 1, rating, dpInc);
            ans += solveDecreasing(i, 1, rating, dpDec);
        }

        
        return ans;
        
    }
};