class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.size();
        if(n%2 != 0) return false;
        int opencnt = 0;

        for(int i=0; i<n; i++)
        {
            if(s[i] == '(' || locked[i] == '0')
            {
                // i can treat this idx as open bracket
                opencnt++;
            }
            else
            {
                opencnt--;
                if(opencnt < 0) return false;
            }
        }

        // if opencnt > 0 or opencnt == 0 Though once ust check the closecnt from right to check to confirm for all testcases
        int closedcnt =0;

        for(int i=n-1; i>=0; i--) //  right to left
        {
            if(s[i] == ')' || locked[i] == '0')
            {
                // i can treat this idx as closed bracket
                closedcnt++;
            }
            else
            {
                closedcnt--;
                if(closedcnt < 0) return false;
            }
        }

        return true;
    }
};