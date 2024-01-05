class Solution {
public:
    void findCombi(int idx, int target, vector<int>& arr, vector<int>& capturedNums, vector<vector<int>>& ans)
    {
        if(idx == arr.size())
        {
            if(target == 0)
            {
                ans.push_back(capturedNums);
                return;
            }
            else
            {
                return;
            }
        }

        if(target >= arr[idx])
        {
        //PICK
        capturedNums.push_back(arr[idx]);
        findCombi(idx, target - arr[idx], arr, capturedNums, ans);
        //pop the element from captured to make space and explore other elements also
        capturedNums.pop_back();
        }

        //NON PICK
        findCombi(idx + 1, target, arr, capturedNums, ans);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //this ans will be returned
        vector<vector<int>> ans;
        //the data structure we will use to store the subsets formed at each stage
        vector<int> ds;
        findCombi(0, target, candidates,ds, ans);

        return ans;
    }
};