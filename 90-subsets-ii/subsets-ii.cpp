class Solution {
public:
    void solve(int idx, vector<int>& temp, vector<vector<int>>& ans, vector<int>& nums)
    {
        // Ques -> 1 2 2 2 3 3
        if(idx == nums.size())
        {
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(nums[idx]);
        solve(idx+1, temp, ans, nums);
        
        temp.pop_back();

        //increment idx until you get different value for this size subset
        while(idx < nums.size() - 1 && nums[idx] == nums[idx+1]) idx++;

       
        solve(idx + 1,temp, ans, nums);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        solve(0, temp, ans, nums);
        return ans;
    }
};