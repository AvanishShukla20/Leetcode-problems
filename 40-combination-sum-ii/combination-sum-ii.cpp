class Solution {
public:
    void validCandidates(int i, vector<int>& candidates, int target, vector<int>& temp, vector<vector<int>>& ans)
    {
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }
        if(i == candidates.size()) return;  
        //pick
        
        if(target >= candidates[i])
        {
            temp.push_back(candidates[i]);
            validCandidates(i+1, candidates, target - candidates[i], temp, ans);
            temp.pop_back();
        }
        while(i+1 < candidates.size() && candidates[i] == candidates[i+1]) i++;
        //non pick
        validCandidates(i+1, candidates, target, temp, ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        validCandidates(0,candidates,target,ds, ans);
        return ans;
    }
};