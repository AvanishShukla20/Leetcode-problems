class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int n = bounds.size();
        int valid_start = bounds[0][0], valid_end = bounds[0][1];
        int CumulativeNeededDiff = 0;
        for(int i=1; i<n; i++)
        {
            CumulativeNeededDiff += (original[i]-original[i-1]);

            valid_start = max(valid_start, bounds[i][0] - CumulativeNeededDiff);
            valid_end = min(valid_end, bounds[i][1] - CumulativeNeededDiff);
        }

        //cout<<"v1 :"<<valid_start<<" "<<valid_end<<endl;
        int ans = valid_end - valid_start + 1;
        return (ans < 0) ? 0 : ans;
    }
};