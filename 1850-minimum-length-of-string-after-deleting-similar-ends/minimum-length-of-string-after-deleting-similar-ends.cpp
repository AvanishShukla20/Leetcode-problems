class Solution {
public:
    int minimumLength(string s) {
       int n = s.size();
       int i=0, j=n-1;
       while(i < j)
       {
           if(s[i] == s[j])
           {
                char x = s[i];
                while(i<=j &&s[i] == x) i++;
                while(j>=i && s[j] == x) j--;
           }
          else break;   
       }
       
       return j - i + 1; 
    }
};