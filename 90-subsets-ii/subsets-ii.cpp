class Solution {
public:

    void Subsets(int i, vector<int>& nums, vector<int>& temp, set<vector<int>>& s)
    {
        if(i == nums.size())
        {
            s.insert(temp);
            return;
        }
        //pick
        temp.push_back(nums[i]);
        Subsets(i+1,nums,temp,s);
        temp.pop_back();
        
        // non - pick
        Subsets(i+1,nums,temp,s);
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
     sort(nums.begin(), nums.end());
     
     vector<int> ds;
     set<vector<int>> s;
     Subsets(0,nums,ds,s);
     vector<vector<int>> ans(s.begin(), s.end());
     return ans;   
    }
};