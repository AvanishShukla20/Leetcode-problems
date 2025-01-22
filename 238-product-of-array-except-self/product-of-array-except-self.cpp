class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> prPdt(n);

        //vector<int> sfPdt(n);
        int pdt = 1;
        prPdt[0] = 1;
        for(int i=1; i<n; i++)
        {
            pdt *= nums[i-1];
            prPdt[i] = pdt;
        }

        pdt = 1;
        for(int i=n-2; i>=0; i--)
        {
            pdt *= nums[i+1];
            prPdt[i] *= pdt;
        }

        
        return prPdt;
    }
};