class Solution {
public:
    void findPermutations(vector<int>& arr, vector<int>& ds, vector<vector<int>>& ans, unordered_map<int,int> visitedValue)
    {
        //ds -> data structure
        if(ds.size() == arr.size())
        {
            ans.push_back(ds);
            return;
        }

        for(int i = 0 ; i < arr.size(); i++)
        {
            //we check if the element is already added in our ds . If yes then we skip it
            if(visitedValue[arr[i]] != 0)
            {
                continue;
            }


            ds.push_back(arr[i]);
            visitedValue[arr[i]] = 1;
            findPermutations(arr,ds,ans,visitedValue);
            visitedValue[arr[i]] = 0;
            ds.pop_back();
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        unordered_map<int,int> mpp;
        findPermutations(nums,ds,ans,mpp);
        return ans;
    }
};