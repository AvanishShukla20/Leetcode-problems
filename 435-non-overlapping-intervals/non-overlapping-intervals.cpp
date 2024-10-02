class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int i = 0, j = 1, ans =0;
        while(j < n)
        {
            if(intervals[i][1] > intervals[j][0])
            {
                if(intervals[i][1] <= intervals[j][1])
                {
                    ans++;
                }
                else
                {
                    i = j;
                    ans++;
                }
            }
            else
            {
                //no overlap
                i = j; // as their is no overlap then next i idx which me to check with further more j indices wiil be current j onlyy !!
            }
            j++;
        }
        return ans;
    }
};