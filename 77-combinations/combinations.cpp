class Solution {
public:
    void solve(int idx, vector<int>&temp,vector<vector<int>>& ans,int k, int n)
    {
        if(k == 0)
        {
            ans.push_back(temp);
            return;
        }

        for(int i = idx; i <= n; i++)
        {
            temp.push_back(i);
            solve(i+1,temp, ans, k-1, n);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(1,temp, ans, k, n);

        return ans;

    }
};
