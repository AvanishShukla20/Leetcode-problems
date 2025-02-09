class Solution {
public:
    
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        unordered_map<int, int> mpp;
        int n = groups.size(), m= elements.size();
        vector<int> ans(n, -1);
        for(int i=0; i<m; i++)
        {
            if(mpp.find(elements[i]) == mpp.end())
            {
                mpp[elements[i]] = i;
            }
        }

        for(int i=0; i<n; i++)
        {
            int num = groups[i];
            int mini = 1e6;
            for(int x = 1; x <= sqrt(num); x++)
            {
                if(num%x == 0)
                {
                    int x1 = x;
                    int x2 = num/x;

                    if(mpp.find(x1) != mpp.end()) mini = min(mini, mpp[x1]);
                    if(mpp.find(x2) != mpp.end()) mini = min(mini, mpp[x2]);
                }
            }

            if(mini != 1e6) ans[i] = mini;
        }

        return ans;
    }
};