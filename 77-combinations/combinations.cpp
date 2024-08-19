class Solution {
public:
    void solve(int idx, vector<int>&temp,vector<vector<int>>& ans,int k, int n)
    {
        if(k == 0)
        {
            ans.push_back(temp);
            return;
        }
        if(idx == n + 1) return;
        //take and explore
        temp.push_back(idx);
        solve(idx+1,temp, ans, k-1, n);
        temp.pop_back();

        solve(idx+1,temp, ans, k, n);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        unordered_set<int> st;
        vector<int> temp;

        solve(1,temp, ans, k, n);

        return ans;

    }
};