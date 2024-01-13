class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0 || intervals.size() == 1) return intervals;

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        vector<int> tempV = {intervals[0][0], intervals[0][1]}; // store interval (NOW -> {1,3} stored)

         
        for(auto range : intervals)
        {
            if(range[0] <= tempV[1])
            {
                tempV[1] = max(range[1], tempV[1]);
            }
            else
            {
                ans.push_back(tempV);
                tempV[0] = range[0];
                tempV[1] = range[1];
            }
        }

        ans.push_back(tempV);
        return ans;
    }
};