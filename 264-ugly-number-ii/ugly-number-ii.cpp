class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ans(n+1); // ans[i] will store my ith ugly no
        ans[1] = 1;

        int i2 = 1, i3 = 1, i5 = 1;

        for(int i = 2; i<= n; i++)
        {
            int temp2 = 2*ans[i2];
            int temp3 = 3*ans[i3];
            int temp5 = 5*ans[i5];

            int ithUgly = min(temp2, min(temp3, temp5));
            ans[i] = ithUgly;

            if(ithUgly == temp2)
            {
                // i2 ko badhayenge kyonki ye iteration me uske index ka element to use hogya . So, next iteration ke liye use doore idx ko pint krna hoga jo valid ans de ske
                i2++;
            }
            if(ithUgly == temp3) i3++;
            if(ithUgly == temp5) i5++ ;

        }

        return ans[n];

    }
};