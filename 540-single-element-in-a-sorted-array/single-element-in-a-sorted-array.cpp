class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n <= 1) return nums[0];

        int ans = -1, low=0, mid, high = n-1;
        int checkidx; // deciding factor
        while(low <= high)
        {
            mid = low+(high-low)/2;
            checkidx = mid;

            if(mid+1 < n && nums[mid] == nums[mid+1]) checkidx++;
            if((mid-1 >= 0 && nums[mid] != nums[mid-1]) &&  (mid+1 < n && nums[mid] !=  nums[mid+1]))
            {
                return nums[mid];
            } 

            if(checkidx%2 != 0)
            {
                low = mid+1;
            }
            else high = mid-1;
        }

        return nums[low];
        
    }
};