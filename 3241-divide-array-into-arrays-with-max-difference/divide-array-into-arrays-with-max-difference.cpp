class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int  n = nums.size();
        for(int i = 0 ; i < n - 2; i = i+3)
        {
            if(nums[i + 2] - nums[i] <= k)
            {
                //we can form 3 elements upto i+2 index
                cout<<"ran this loop : "<<endl;
                ans.push_back({nums[i], nums[i+1], nums[i+2]});
            }
            else return {};
        }
        return ans;
    }
};