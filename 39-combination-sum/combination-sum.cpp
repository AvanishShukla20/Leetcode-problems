class Solution {
public:
    /* Since this ques tells us that candidates is distinct That's why there is no chance of having a DUPLICATE valid Combination in our approach */

    vector<vector<int>> ans;
    void findValidCombinations(vector<int>& candidates, int target, int idx, vector<int>& validcandidate)
    {

        if(idx == candidates.size())
        {
            if(target == 0)
            {
                ans.push_back(validcandidate);
                // we have not done pop_back here as this call will always be returned as a nonpick condition
            }
            return;
        }
        

        if(target - candidates[idx] >= 0)
        {
            validcandidate.push_back(candidates[idx]);
            cout<<target<<" ";
            findValidCombinations(candidates, target - candidates[idx], idx,validcandidate);
            cout<<target<<endl;
            validcandidate.pop_back();
        }


        // Why i am not doing any check of target below as i have done before ? ->
        /* It is because this step does not affects the target at all */

        /*NON-PICK*/ findValidCombinations(candidates, target , idx+1, validcandidate);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.size() == 0) return {};
        vector<int> validcandidate;
        int idx = 0;
        findValidCombinations(candidates, target, idx, validcandidate);
        return ans;
    }
};