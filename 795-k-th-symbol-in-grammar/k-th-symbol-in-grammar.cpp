class Solution {
public:
    int kthGrammar(int n, int k) {
       if(n == 1 && k == 1) return 0;

       //calculated mid by observation
       int mid = pow(2,n-1)/2 ;

       if(k <= mid)
       {
           //upto mid term the curr string is copy of previous string So same k will give answer
           return kthGrammar(n-1,k);
       }
       //The other half is the copy of Complement of previous string
       else
       {
           return kthGrammar(n-1, k - mid)^1; // flipping the bit returned by kthgrammar function using XOR
       } 
    }
};