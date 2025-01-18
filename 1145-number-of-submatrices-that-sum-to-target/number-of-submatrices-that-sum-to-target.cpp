class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m= matrix.size(), n= matrix[0].size();
        vector<vector<int>> pfSumGrid = matrix;
        
        int ans =0;
        for(int i=0; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                pfSumGrid[i][j] += pfSumGrid[i][j-1];
            }
        }

        

        for(int start_col = 0; start_col < n; start_col++)
        {
            
            for(int j=start_col; j<n; j++)
            {
                unordered_map<int, int> mpp;
                mpp[0] = 1;
                int cumSum = 0;

                for(int row = 0; row < m; row++)
                {
                    cumSum += pfSumGrid[row][j] - ((start_col > 0) ? pfSumGrid[row][start_col-1] : 0);
                    if(mpp.find(cumSum - target) != mpp.end())
                    {
                        ans += mpp[cumSum-target];
                    }
                    mpp[cumSum]++;
                }
                
            }
        }
        


        return ans;

    }
};