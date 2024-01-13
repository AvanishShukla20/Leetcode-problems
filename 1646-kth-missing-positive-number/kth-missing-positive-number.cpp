class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // Optimal Binary search approach
        int n = arr.size();
        int low = 0, high = n-1,mid;
        while(low <= high)
        {
            mid = low+(high - low)/2;
            int NoOfMissings = arr[mid] - (mid + 1);
            if(NoOfMissings < k){
                low =  mid+1;
            }
            else
            {
                high = mid-1;
            } 
        }

        return high + k + 1;
    }
};