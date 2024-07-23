class Solution {
public:
    
    int kthGrammar(int n, int k) {
        if(n == 1) return 0;
        int middlepos = pow(2, n -2);

        if(k <= middlepos)
        {
            return kthGrammar(n - 1, k);
        }
        else
        {
            int r = kthGrammar(n - 1, k - middlepos);
            return r^1;
        }
    }
};