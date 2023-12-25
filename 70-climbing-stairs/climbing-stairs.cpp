class Solution {
public:
    // Here in this Ques You learn a memoization technique to drastically reduce the number of function callls with same parameters

    //we take help of a storage data structure to update values of obtained function call values in it


    int calculateSteps(int n, unordered_map< int,int >& map){
        // base case 
        if(n==0 || n==1)
        {
            map[n] = 1;
            return map[n] ;
        } 
        else if( map.find(n) == map.end())
        {
            map[n] = calculateSteps(n-1, map) + calculateSteps(n-2, map);
        }
        return map[n];
    }

    int climbStairs(int n) {
        unordered_map< int,int > mpp;
        int res = calculateSteps(n, mpp);
        return res;
    }
};