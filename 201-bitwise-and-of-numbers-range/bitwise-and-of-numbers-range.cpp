class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {   
        while(right > left)
        {
            //removing leftmost set bit each time and initialise that value into right again
            right = right & (right - 1);
        }

        return right;
    }
};