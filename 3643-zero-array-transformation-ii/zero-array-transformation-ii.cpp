class Solution {
public:
    bool isPossible(int mid, vector<int>& nums, vector<vector<int>>& queries)
    {
        int n=nums.size();
        vector<int> diffarray(n, 0);

        for(int i=0; i<mid; i++)
        {
            int l = queries[i][0], r = queries[i][1], val = queries[i][2];
            diffarray[l] -= val;
            if(r+1 < n) diffarray[r+1] += val;
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
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int low = 0, high = queries.size(), mid;
        int ans = -1;

        while(low <= high)
        {
            mid=low+(high-low)/2;

            if(isPossible(mid, nums, queries) == true)
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        return ans;
    }
};