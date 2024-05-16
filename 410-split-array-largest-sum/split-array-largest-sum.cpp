class Solution {
public:
    int kNeeded(vector<int>& nums, int& maxallowed)
    {
        int i =1, pSum = nums[0], k = 1;
        while(i < nums.size())
        {
            pSum += nums[i];
            if(pSum > maxallowed)
            {
                k++;
                pSum = 0;
            }
            else i++; 
        }
        return k;
    }

    int sum(vector<int>& nums)
    {
        int n = nums.size(), res = 0;
        for(int i=0; i<n; i++)
        {
            res += nums[i];
        }
        return res;
    }

    int splitArray(vector<int>& nums, int k) {

        // must see the solution of book allocation by striver to understand this approach
      int low = *max_element(nums.begin(), nums.end());
      int high = sum(nums);
      int ans = INT_MAX;

      while(low <= high)
      {
        int mid = low + (high - low)/2;

        int kRequiredforMid = kNeeded(nums, mid);
        if(kRequiredforMid == k)
        {
            ans = min(ans, mid);
            high = mid - 1;
        }
        else if(kRequiredforMid < k) high = mid - 1;
        else low = mid + 1;
      }

      if(ans == INT_MAX) return low;
      return ans;  
    }
};