class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int ansSize=0;
        for(int i=0; i<nums.size(); i++)
        {

            mpp[nums[i]]++;
        }
         //size of ans vector
        for(auto t : mpp)
        {
            if(t.second > ansSize) ansSize = t.second;
        }


        vector<vector<int>> ans(ansSize);

        //inserting elements in ans vector of vector
        for(auto x : mpp)
        {
            int i=0;
            while(i < x.second)
            {
                ans[i].push_back(x.first);
                i++;
            }
        }
        return ans;
    }
};