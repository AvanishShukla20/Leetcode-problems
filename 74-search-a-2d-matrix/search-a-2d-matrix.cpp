class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n=matrix[0].size();
        int rlow = 0, rhigh = m-1, rmid;
        int val = target;
        while(rlow <= rhigh)
        {
            rmid = rlow + (rhigh-rlow)/2;

            if(matrix[rmid][0] <= val && matrix[rmid][n-1] >= val)
            {
                // search in logn time
                int jl = 0, jh = n-1, mid;
                while(jl <= jh)
                {
                    mid = jl + (jh-jl)/2;

                    if(val == matrix[rmid][mid]) return true;
                    else if(val < matrix[rmid][mid])
                    {
                        jh = mid-1;
                    }
                    else jl = mid+1;
                }

                break;
            }
            else if(val < matrix[rmid][0])
            {
                rhigh = rmid-1;
            }
            else rlow = rlow + 1;
        }

        return false;
    }
};