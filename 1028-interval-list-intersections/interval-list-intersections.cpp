class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int m=firstList.size(), n=secondList.size();
        int i=0,j=0;

        vector<vector<int>> ans;
        while(i<m && j<n)
        {
            int ll = max(firstList[i][0], secondList[j][0]);
            int ul = min(firstList[i][1], secondList[j][1]);
            if(ll <= ul) ans.push_back({ll, ul});
            if(firstList[i][1] <= secondList[j][1]) i++;
            else j++;
        }
        return ans;
    }
};