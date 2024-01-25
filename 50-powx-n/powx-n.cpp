class Solution {
public:
    double calculateRes(double x, int n)
    {
        if(n==0)
        {
            return 1;
        }
        double res = myPow(x, n/2);

        res *= res;
        if(n%2 !=0) res *= x;

        return res;
    }
    double myPow(double x, int n) {
        double ans = calculateRes(x,abs(n));
        if(n<0) return 1.00/ans;
        else return ans;
    }
};