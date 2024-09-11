class Solution {
public:
    int power(int a, int b)
    {
        //binary exponentiation method (iterative)
        int num = 1;
        while(b != 0)
        {
            if(b&1) num *= a;
            a *= a;
            b >>= 1;
        }
        return num;
    }
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int pigs = 0;
        int trials = minutesToTest/minutesToDie;
        int T = trials + 1;
        while(power(T, pigs) < buckets)
        {
            pigs++;
        }
        return pigs;
    }
};