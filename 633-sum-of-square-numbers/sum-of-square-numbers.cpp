class Solution {
public:
    bool judgeSquareSum(int c) {
        long l = 0, h = sqrt(c);
        while(l <= h)
        {
            if(l*l + h*h == c) return true;
            else if(l*l + h*h < c)
            {
                l += 1;
            }
            else
            {
                h -= 1;
            }
        }

        return false;
    }
};