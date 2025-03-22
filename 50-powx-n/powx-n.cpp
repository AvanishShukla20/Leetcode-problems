class Solution {
public:
    double solve(double x, int n)
    {
        if(n == 0) return 1;

        double res = 1;
        double p = solve(x, n/2);
        
        res = p*p;

        if(n%2 != 0) res *= x;
        return res;
    }
    double myPow(double x, int n) {

        double ans = solve(x, n);
        if(n < 0) ans = 1/ans;
        return ans;
    }
};