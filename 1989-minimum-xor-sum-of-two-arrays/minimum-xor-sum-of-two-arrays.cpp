class Solution {
public:
    int solve(int i, vector<int>& nums1, vector<int>& nums2,vector<vector<int>>& dp, int num)
    {
        int n=nums1.size();
        if(i >= n) return 0;
        if(dp[i][num] != -1) return dp[i][num];
        int mini = 1e9;

        cout<<" i : "<<i<<endl;
        for(int j =0; j<n; j++)
        {
            if((num&(1<<j)) == 0)
            {
                mini = min(mini, (nums1[i]^nums2[j]) + solve(i+1, nums1, nums2,dp, num|(1<<j) ));
            }
        }

        return dp[i][num] = mini;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<vector<int>> dp(n+1, vector<int> (1<<16, -1));
        int num = 0;
        return solve(0, nums1, nums2,dp, num);
    }
};