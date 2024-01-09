class Solution {
public:
    int balancedStringSplit(string s) {
        int rCount=0, lCount=0,ans=0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == 'L') lCount++;
            else rCount++;
        }

        for(int i=s.size() -1 ; i>=0; i--)
        {
            if(s[i] == 'L') lCount--;
            else rCount --;
            if(rCount == lCount) ans++;
        }
        return ans;
    }
};