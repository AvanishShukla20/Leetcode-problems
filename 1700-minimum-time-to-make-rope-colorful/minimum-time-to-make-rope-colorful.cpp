class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i=0, j=1,ans=0;
        while(j < colors.size())
        {
            if(colors[i]==colors[j])
            {
                if(neededTime[i] <= neededTime[j])
                {
                    ans += neededTime[i];
                    i=j;
                    j++;
                }
                else
                {
                    ans += neededTime[j];
                    j++;
                }
            }
            else
            {
                i = j;
                j++;
            }
        }
        return ans;
    }
};