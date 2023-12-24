class Solution {
public:
    int minOperations(string s) {
        int ans1=0, ans2=0;
        int next ;
        // the mistake of yours is actually we have to find minimum no of flips to make alternate bibary string so we take two cases 
        //counting if we take alternating string to start from 0
        next = 0;
        for(int i=0; i< s.size(); i++)
        {
            if(s[i] - '0' != next)
            {
                ans1++;
            }

            next = (next + 1) % 2;
        }

        // now checking for ans in case we start alterenating string from 1
        next=1;
        for(int i=0; i< s.size(); i++)
        {
            if(s[i] - '0' != next)
            {
                ans2++;
            }

            next = (next + 1) % 2;
        }

        return min(ans1,ans2);
    }
};