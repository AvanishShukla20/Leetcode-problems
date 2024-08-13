class Solution {
public:
    void solve(int idx, vector<int>& temp, vector<vector<int>>& ans, vector<int>& nums)
    {
        // Ques -> 2 2 2 3
        if(idx == nums.size())
        {
            ans.push_back(temp);
            return;
        }
        // use 2 and find for 2 2 3
        temp.push_back(nums[idx]);
        solve(idx+1, temp, ans, nums);
        // remove 2
        temp.pop_back();

        //increment idx until you get different element
        while(idx < nums.size() - 1 && nums[idx] == nums[idx+1]) idx++;

        // 3 is different so call for it
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