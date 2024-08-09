class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> res;
        int n = security.size(), j;
        vector<int> after(n, 0);
        vector<int> before(n, 0);

        for(int i = n-1; i>= 1; i--)
        {
            if(security[i-1] <= security[i])
            {
                after[i-1] = after[i] + 1;
            }
        }
        for(int i = 0; i < n-1; i++)
        {
            if(security[i] >= security[i+1])
            {
                before[i+1] = before[i] + 1;
            }
        }

        for(int i = 0; i< n; i++)
        {
            if(before[i] >= time && after[i] >= time) res.push_back(i);

        }
        return res;
    }
};