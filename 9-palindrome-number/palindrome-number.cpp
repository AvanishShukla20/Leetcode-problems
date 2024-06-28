class Solution {
public:
    bool isPalindrome(long long int x) {
        long long int t=x;
        long long int rem,res=0;
        if(x>=0){
            while(t!=0){
            rem=t%10;
            res=res*10+rem;
            t=t/10;
        }
        if(res!=x){
            return false;
        }
        else{
            return true;
        }
    }
        return false;
    }   
};