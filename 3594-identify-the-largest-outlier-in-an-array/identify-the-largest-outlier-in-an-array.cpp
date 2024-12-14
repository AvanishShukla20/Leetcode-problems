class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, ans = -1e6;
        unordered_map<int, int> mpp;
        for(int i=0;i<n; i++)
        {
            sum += nums[i];
            mpp[nums[i]]++;
        }

        for(int i=0; i<n; i++)
        {
            if((sum-nums[i])%2 != 0) continue;
            int search = (sum - nums[i])/2;
            mpp[nums[i]]--;
            if(mpp[nums[i]] == 0) mpp.erase(nums[i]);
            if(mpp.find(search) != mpp.end())
            {
                cout<<nums[i]<<" "<<search<<endl;
                if(mpp[search] != 0) ans = max(ans, nums[i]);
            }
            mpp[nums[i]]++;
        }
        
        return ans;
    }
};