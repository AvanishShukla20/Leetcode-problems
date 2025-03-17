class Solution {
public:
    bool isvalid(int val,int k, vector<int>& nums)
    {
        int cnt = 0;
        for(int i=0; i<nums.size();)
        {
            if(nums[i] <= val)
            {
                cnt++;
                i++;
            }
            i++;
        }

        return cnt >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int, int> mpp;
        for(int i=0; i<nums.size(); i++)
        {
            mpp[nums[i]] = i;
        }
        
        int low = 1, high = *max_element(nums.begin(), nums.end()), mid, ans = high;

        while(low <= high)
        {
            mid = low + (high-low)/2;
            if(isvalid(mid,k, nums) == true)
            {
                ans = mid; 
                high = mid-1;
            }
            else low = mid+1;
        }

        return ans;
        
    }
};