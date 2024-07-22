class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int, string> mpp;

        for(int i = 0; i< heights.size(); i++)
        {
            mpp[heights[i]] = names[i];
        }

        sort(heights.begin(), heights.end(), greater<int>() );

        vector<string> ans;
        for(auto &it : heights)
        {
            ans.push_back(mpp[it]);
        }
        return ans;
    }
};