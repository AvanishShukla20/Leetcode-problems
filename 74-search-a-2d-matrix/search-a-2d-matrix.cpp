class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      // most optimum solution ->
      int n = matrix.size(),m = matrix[0].size();
      int  low =0, high =  n*m -1, mid;
      while(low <= high)
      {
          mid = low + (high-low)/2;
          //converting mid (1d data) into row and column no (2d coordinates) -> we use m (i.e no of elements per row) to calculate
          int rowNo = mid / m;
          int colNo = mid % m;

          if(matrix[rowNo][colNo] == target) return true;

          else if (matrix[rowNo][colNo] > target) high = mid -1;

          else low = mid+1;
      }

      return false;
    }
};