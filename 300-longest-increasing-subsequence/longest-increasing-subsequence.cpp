class Solution {
public:
    int solve(int& el, vector<int>& ans)
    {
        int res = 0, low = 0, high = ans.size()-1,mid;
        while(low <= high)
        {
            mid = low + (high-low)/2;
            if(ans[mid] >= el)
            {
                res = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        return res;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);

        for(int i=1; i<nums.size(); i++)
        {
            if(ans.back() < nums[i])
            {
                ans.push_back(nums[i]);
            }
            else
            {
                int idx = solve(nums[i], ans);
                ans[idx] = nums[i];
            }
        }
        for(auto it : ans) cout<<it<<" ";
        return ans.size();
    }
};