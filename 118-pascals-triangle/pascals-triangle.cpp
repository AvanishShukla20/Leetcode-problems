class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        ans[0] = {1};
        if(numRows == 1) return ans;
        ans[1] = {1, 1};
        if(numRows == 2) return ans;

        vector<int> prev = ans[1];

        for(int i=2; i<numRows; i++)
        {
            vector<int> curr(i+1);
            int n = i+1;
            curr[0] = 1;
            curr[n-1] = 1;

            int j = 1, k = 0;
            while(k < n-2 )
            {
                curr[j] = (prev[k] + prev[k+1]);
                k++;
                j++;
            }

            ans[i] = curr;
            prev = curr;
        }

        return ans;
    }
};