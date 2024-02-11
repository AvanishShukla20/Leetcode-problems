class Solution {
public:
    int BinSearch(vector<int>& nums, int low, int high, int target)
    {
        int mid;
        while(low <= high)
        {
            mid = low+(high-low)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) low = mid+1;
            else high = mid-1;
        } 
        return -1;
    }

    // main learning of this Ques
    int findPivot(vector<int>& arr, int left, int right)
    {
        int mid;
        while(left < right)
        {
            mid = left + (right-left)/2;

            if(arr[mid] > arr[right]) left = mid+1;
            else right = mid;
        }
        return left;
    }
    int search(vector<int>& nums, int target) {
        // right -> last idx
        int n = nums.size();
        int pivotIdx = findPivot(nums, 0, n-1);
        
        int ans = -1;
        // apply binsearch from 0 to pivot-1
        ans = BinSearch(nums, 0, pivotIdx-1,target);
        
        if(ans == -1) ans = BinSearch(nums, pivotIdx, n-1,target);
        
        return ans;

    }
};