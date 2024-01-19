class Solution {
public:

    void Subsets(int i, vector<int>& nums, vector<int>& temp, set<vector<int>>& s,vector<vector<int>>& ans)
    {
        if(i == nums.size())
        {
            
            if(s.find(temp) == s.end()) ans.push_back(temp);
            s.insert(temp);
            return;
        }
        //pick
        temp.push_back(nums[i]);
        Subsets(i+1,nums,temp,s,ans);
        temp.pop_back();
        
        // non - pick
        Subsets(i+1,nums,temp,s,ans);
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
     sort(nums.begin(), nums.end());
     vector<vector<int>> ans;
     vector<int> ds;
     set<vector<int>> s;
     Subsets(0,nums,ds,s,ans);
     return ans;   
    }
};