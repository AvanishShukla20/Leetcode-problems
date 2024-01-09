class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int midIdx, n = s.size(), i, j;

        //size of string is odd

        if(n&1)
        {
            midIdx = n/2;
            i = midIdx + 1;
            j = midIdx - 1;
            while(i<n){
            if(s[j] != s[i])
            {
                //new thing of initialisation->
                s[j] = s[i] = min(s[i],s[j]);    
            }
            j--;
            i++;
            }
        }
        //if size of string is even
        else
        {
            midIdx = n/2 -1;
            j = midIdx;
            i = midIdx + 1;
            while(j>=0 and i<n)
            {
                if(s[j] != s[i])
                {
                    s[j] = s[i] = min(s[j],s[i]);
                }
                j--;
                i++;
            }
        }
        return s;
    }
};