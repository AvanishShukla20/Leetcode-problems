class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> hash(n);
        int maxi = 0,idx = 0;

        for(int i = 0; i < n; i++)
        {
            hash[i] = i;
            for(int j = 0; j < i; j++)
            {
                if(nums[i]%nums[j] == 0 && dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j]+1;
                    hash[i] = j;
                    if(dp[i] > maxi)
                    {
                        idx = i;
                        maxi = dp[i];
                    }
                }
            }
        }

        vector<int> ans;
        
        while(hash[idx] != idx)
        {
            ans.push_back(nums[idx]);
            idx = hash[idx];
        }

        ans.push_back(nums[idx]);
        return ans;
    }
};