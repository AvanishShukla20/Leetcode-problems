class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // carefully observe that it is saying you to select cards consecutively if choosen(all k cards need not be necessarily consecutively chosen)
        int sum = 0, lSum =0, rSum = 0, n = cardPoints.size(), ans = 0;
        int i = 0;
        for(; i < k; i++)
        {
            lSum += cardPoints[i];
        }
        ans = max(ans, lSum);


        int rptr =  n - 1;
        int lptr = k - 1;
        sum = lSum;

        for(int j = lptr; j >= 0; j--)
        {
            sum -= cardPoints[j];
            sum += cardPoints[rptr];
            ans = max(ans, sum);
            rptr--;
        }

        return ans;


    }
};