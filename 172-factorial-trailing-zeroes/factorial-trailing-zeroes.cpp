class Solution {
public:
    int trailingZeroes(int n) {
        int div=1,res=0,control;
        while(control != 0)
        {
            div = div*5;
            control = n/div;
            res += control ;
        }
        return res;
    }
};