class Solution {
public:
    int longestValidParentheses(string s) {
      if(s.size() == 0 || s.size() == 1) return 0;
      int leftBracket = 0,rightBracket = 0, ans = 0;

        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '(') leftBracket++ ;
            else rightBracket++ ;
            if(leftBracket == rightBracket)
            {
                ans = max(ans, 2*leftBracket);
            }
            else if(rightBracket > leftBracket)
            {
                leftBracket = 0;
                rightBracket = 0;
            }
        }
        /*Do the same in reverse direction also */
        leftBracket = 0;
        rightBracket = 0;
        for(int i= s.size() - 1 ; i >= 0; i--)
        {
            if(s[i] == '(') leftBracket++ ;
            else rightBracket++ ;
            if(leftBracket == rightBracket)
            {
                ans = max(ans, 2*leftBracket);
            }
            else if(leftBracket > rightBracket)
            {
                leftBracket = 0;
                rightBracket = 0;
            }
        }
        return ans;
    }
};