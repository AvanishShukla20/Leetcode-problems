class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        int ans = INT_MAX;

        vector<int> dplis(nums.size(), 1);

        for(int i = 0; i<n; i++)
        {
            for(int j = i-1; j>=0; j--)
            {
                if(nums[j] < nums[i]) 
                {
                    dplis[i] = max(dplis[i], dplis[j]+1);
                    
                }
            }
            
        }

        vector<int> dplds(nums.size(), 1);

        for(int i = n-1; i>=0; i--)
        {
            for(int j = i+1; j<n; j++)
            {
                if(nums[j] < nums[i]) 
                {
                    dplds[i] = max(dplds[i], dplds[j]+1);
                }
            }
        }


        for(int i=0; i<n; i++)
        {
            // at each iteration i is assumed as peak 
            int l1 = dplis[i];
            cout<<l1<<" ";
            int l2 = dplds[i];
            cout<<l2<<endl;
            if(l1 > 1 && l2 > 1) // this is added so as when i have roots clear to make this idx as peak I will not delte this idx itself
            {
                int toRemove = n+1-(l1+l2);
                ans = min(ans, toRemove);
            }
            
        }

        return ans;
    }
};