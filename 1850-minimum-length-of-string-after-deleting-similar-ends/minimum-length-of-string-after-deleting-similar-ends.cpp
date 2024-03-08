class Solution {
public:
    int minimumLength(string s) {
       int n = s.size();
       int i=0, j=n-1;
       while(i < j) // not put i <= j as i can't make prefix and suffix intersect
       {
           if(s[i] == s[j])
           {
                char x = s[i]; 
                /* In every loop you have to again pust i<j type constraint because
                YOU CAN never let your pointers move endlessly just by checking 
                that s[i] or s[j] == x .HENCE AT EVERY STEP WE MUST APPLY CONSTRAINTS
                IN BOTH THE WHILE LOOPS BELOW */
                while(i < j &&s[i] == x) i++;
                while( i <= j && s[j] == x) j--; // MAIN CATCH -> note the "<=" condition is there not "<"
           }
          else break;   
       }
       
       return j - i + 1; 
    }
};