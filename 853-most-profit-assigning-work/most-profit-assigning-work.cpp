class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {


        vector<pair<int, int>> diffProfit;

        for(int i =0; i < difficulty.size(); i++)
        {
            diffProfit.push_back({difficulty[i], profit[i]});
        }


        sort(diffProfit.begin(), diffProfit.end());
        sort(worker.begin(), worker.end());


        int j = 0, sum = 0, n = worker.size(), add = 0;
        for(int i = 0; i < n; i++)
        {
            int maxdiff = worker[i];
            
            cout<<"maxdiff : "<<maxdiff<<" ";
            while(j < diffProfit.size() && maxdiff >= diffProfit[j].first)
            {
                add = max(add, diffProfit[j].second);
                j++;
            }
            sum += add;
        }
        return sum;
    }
};