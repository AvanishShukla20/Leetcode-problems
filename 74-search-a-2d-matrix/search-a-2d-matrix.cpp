class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n = matrix[0].size();
        int val = target;
        int low = 0, high = m*n-1, mid;

        while(low <= high)
        {
            mid = low + (high-low)/2;
            int r = mid/n;
            int c = mid%n;

            if(matrix[r][c] == val) return true;
            else if(matrix[r][c] < val)
            {
                low = mid+1;
            }
            else high = mid-1;
        }
        return false;
    }
};