class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        
        sort(intervals.begin(), intervals.end());

        int h=intervals[0][1], l = intervals[0][0];
        vector<vector<int>> ans;
        for(int i = 1; i<n; i++)
        {
            int a = intervals[i][0], b=intervals[i][1];
            if(a <= h)
            {
                // overlap since sorted So it will always be a >= l
                h = max(h, b);
            }
            else
            {
                ans.push_back({l, h});
                l = a;
                h = b;
            }
        }

        ans.push_back({l, h});

        return ans;
    }
};