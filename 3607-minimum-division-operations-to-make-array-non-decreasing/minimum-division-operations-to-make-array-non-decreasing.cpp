class Solution {
public:
    void leastfactor(vector<int>& ans, int& maxi)
    {
        vector<int> p(maxi + 1, 0);
        for(int i = 2; i*i<=maxi; i++)
        {
            if(p[i] == 0)
            {
                for(int j = i; j <= maxi; j += i)
                {
                    if(ans[j] == 1)
                    {
                        ans[j] = i;
                    }
                    p[j] = 1;
                }
            }
        }
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> ans(maxi + 1, 1);
        leastfactor(ans, maxi);
        int res = 0;
        for(int i = n-2; i>= 0; i--)
        {
            if(nums[i]>nums[i+1])
            {
                int val = nums[i];
                int d = val/ans[val];
                if(d != val)
                {
                    res += 1;
                    nums[i] = val/d;
                }
            }
        }

        for(int i=0; i<n-1; i++)
        {
            if(nums[i] > nums[i+1]) return -1;
        }

        return res;
    }
};