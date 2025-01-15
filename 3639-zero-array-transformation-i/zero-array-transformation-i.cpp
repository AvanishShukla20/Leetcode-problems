class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> diffarray(n, 0);

        for(int i=0; i<queries.size(); i++)
        {
            int l = queries[i][0], r = queries[i][1];
            diffarray[l] -= 1;
            if(r+1 < n) diffarray[r+1] += 1;
        }

        for(int i=1; i<diffarray.size(); i++)
        {
            diffarray[i] += diffarray[i-1];
        }

        for(int i=0; i<n; i++)
        {
            if((nums[i] + diffarray[i]) > 0) return false;
        }

        return true;
    }
};