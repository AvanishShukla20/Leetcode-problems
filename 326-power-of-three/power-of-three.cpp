class Solution {
public:
    bool isPowerOfThree(int n) {
       if(n == 0) return false;
       if(n == 1) return true;
       
       bool flag ;
       if(n%3 == 0) flag = true;
       else flag = false;
       return flag and isPowerOfThree(n/3); 
    }
};