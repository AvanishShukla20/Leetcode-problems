class Solution {
public:
    vector<vector<int>> container;

    void solve(int target, int k, vector<int>& res, int chosen)
    {
        if(target < 0) return;
        if(target == 0 && k == 0)
        {
            container.push_back(res);
            return;
        }
        for(int choice = chosen + 1; choice <= 9; choice++)
        {
                res.push_back(choice);
                solve(target-choice, k - 1, res, choice);
                res.pop_back();      
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n < k) return {};
        vector<int> res;
        solve(n, k, res, 0);
        return container;
    }
};