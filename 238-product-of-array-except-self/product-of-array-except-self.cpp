class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> prPdt(n);
        vector<int> sfPdt(n);
        int pdt = 1;
        prPdt[0] = 1;
        sfPdt[n-1] = 1;
        for(int i=1; i<n; i++)
        {
            pdt *= nums[i-1];
            prPdt[i] = pdt;
        }

        pdt = 1;
        for(int i=n-2; i>=0; i--)
        {
            pdt *= nums[i+1];
            sfPdt[i] = pdt;
        }

        vector<int> ans(n);
        for(int i=0; i<n; i++)
        {
            ans[i] = prPdt[i]*sfPdt[i];
        }
        return ans;
    }
};