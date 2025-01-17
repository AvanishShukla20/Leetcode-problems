class Solution {
public:
    bool check(int val,int p, vector<int>& nums)
    {
        int i=0, n=nums.size(); 
        cout<<val<<endl;
        while(i < n-1)
        {
            if(nums[i+1]- nums[i] > val)
            {
                // if you cannot pair up these two then increment only by one and check if next two can be validly paired up
                i++;
            }
            else
            {
                p--;
                i+=2;
            }
        }
   
        return (p <= 0) ;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(), nums.end());

        int high = nums[n-1];
        int low = 0, ans = 0, mid;

        while(low <= high)
        {
            mid = low + (high-low)/2;
            if(check(mid,p, nums) == true)
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;

    }
};