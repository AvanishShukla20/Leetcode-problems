class Solution {
public:
    // Here in this Ques You learn a memoization technique to drastically reduce the number of function callls with same parameters

    //we take help of a storage data structure to update values of obtained function call values in it


    int climbStairs(int n, unordered_map< int,int >& mpp){
        // base case 
        if(n==0 || n==1)
        {
            mpp[n] = 1;
            return mpp[n] ;
        } 
        else if( mpp.find(n) == mpp.end())
        {
            mpp[n] = climbStairs(n-1, mpp) + climbStairs(n-2, mpp);
        }
        return mpp[n];
    }

    int climbStairs(int n) {
        unordered_map< int,int > mpp;
        int res = climbStairs(n, mpp);
        return res;
    }
};