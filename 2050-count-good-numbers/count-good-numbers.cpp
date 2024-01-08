#define mod 1000000007
class Solution {
public:
    //approach to calculate
    /* if power (i.e y) is odd ->  x^y = x^(y/2) * x^(y/2) * x;
        if it is even -> x^y =  x^(y/2) * x^(y/2) ;
        */
    long long Power(long long x, long long y)
    {
        
        if(y == 0) return 1;
         
        long long res;
        long long temp = Power(x, y/2);
    
        res = (temp*temp) % mod;

        if(y %2 != 0)
        {
            res *= x;
            res %= mod;
        }
        return res;

    }
    int countGoodNumbers(long long n) {

        long long noOfOddindices = n / 2;
        long long noOfEvenindices;
        if( n%2 != 0) noOfEvenindices = noOfOddindices + 1;
        else noOfEvenindices = noOfOddindices;
        
        //we are solving taking out power using Binary approximation of pow(x,n) function as we define it as custom function here and implement its calculation code

        return  ( Power(5,noOfEvenindices)*(Power(4,noOfOddindices)) ) % mod;

    }
};