class Solution {
public:
    int countAllOccur(int mid, vector<int>& nums)
    {
        int cnt = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] <= mid)
            {
                cnt++;
            }
        }
        return cnt;
    }

    int findDuplicate(vector<int>& nums) {   
        int n=nums.size();
        int l = 1, h = n, mid, ans = 0;
        
        while(l <= h)
        {
            mid = l + (h-l)/2;

            //function to count all element occurrence <= mid
            int cnt = countAllOccur(mid, nums);
            int idealcnt = mid;

            if(cnt > idealcnt)
            {
                ans = mid;
                h = mid-1;
            }
            else l = mid+1;
        }

        return ans;
    }
};