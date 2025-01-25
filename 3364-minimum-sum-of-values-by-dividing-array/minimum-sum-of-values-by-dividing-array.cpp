class Solution {
public:
    int solve(int i, int j, int andvalue, vector<int>& andValues, vector<int>& nums, vector<vector<unordered_map<int, int>>>& dp)
    {
        if(i >= nums.size())
        {
            if(j >= andValues.size()) return 0;
            return 1e8;
        }

        if(j >= andValues.size()) return 1e8;


        if(dp[i][j].find(andvalue) != dp[i][j].end()) return dp[i][j][andvalue];

        int sumIfIncluded = 1e8;

        if((andvalue&nums[i]) == andValues[j])
        {
            // (1<<20) means 10....0 1 and 20 zeroes then (1<<20)-1 means 1000... - 1 => 1111... 20 ones
            sumIfIncluded = nums[i] + solve(i+1, j+1, ((1<<20) - 1), andValues, nums, dp); // i will start fresh from next onwards

        }

        int sumIfExcluded = solve(i+1, j, (andvalue&nums[i]), andValues, nums, dp);// matlab i add this nums[i] and move next idx

       return dp[i][j][andvalue] = min(sumIfIncluded, sumIfExcluded);
    }
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        vector<vector<unordered_map<int, int>>> dp(nums.size(), vector<unordered_map<int, int>>(10));


        int initialValue = (1<<20)-1; // as 1e5 at max contians 18 bits only and we know anding any value in the array always decreases the resultant value or remains same

        int ans = solve(0, 0, initialValue, andValues,nums, dp);
        return (ans == 1e8) ? -1 : ans;
    }
};