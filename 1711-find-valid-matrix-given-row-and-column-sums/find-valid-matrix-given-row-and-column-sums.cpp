class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size(), m = colSum.size();

        vector<vector<int>> grid(n, vector<int>(m, 0));
        vector<int> cumRowSum(n, 0);
        vector<int> cumColSum(m, 0);

        for(int i =0; i< rowSum.size(); i++)
        {
            for(int j =0; j < colSum.size(); j++)
            {
                grid[i][j] = min(rowSum[i] - cumRowSum[i], colSum[j] - cumColSum[j]);

                cumRowSum[i] += grid[i][j];
                cumColSum[j] += grid[i][j];

            }
        }

        return grid;
    }
};