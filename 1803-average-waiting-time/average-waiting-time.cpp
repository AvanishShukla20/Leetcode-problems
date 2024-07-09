class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans = 0;

        int resTime = customers[0][0], waitTime;

        for(int i = 0; i<customers.size(); i++)
        {
            if(resTime >= customers[i][0]) resTime += customers[i][1];
            else resTime = customers[i][0] + customers[i][1];

            waitTime = resTime - customers[i][0];
            ans += waitTime;
        }

        cout<<ans<<endl;
        double result = ans / customers.size();
        return result;

    }
};