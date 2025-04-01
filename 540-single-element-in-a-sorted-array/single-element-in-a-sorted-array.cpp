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
            if(mid == 0)
            {
                if(nums[mid] != nums[mid+1]) return nums[mid];
                else low = mid+1;
            }
            else if(mid == n-1)
            {
                if(nums[mid] != nums[mid-1]) return nums[mid];
                else high = mid-1;
            }
            else
            {
                if(nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1]) return nums[mid];

                int id1 = mid, id2 = mid;
                if(nums[mid] == nums[mid+1]) id2++;
                else if(nums[mid] == nums[mid-1]) id1--;

                if(id1%2 != 0 && id2%2 == 0) high = mid-1;
                else low = mid+1;
            }
        }

        return nums[low];
        
    }
};