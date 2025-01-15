class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int reqcnt =0, cnt = 0, rightmost = 31;

        for(int i=0; i<=31; i++)
        {
            if((num2 & (1<<i)) != 0) reqcnt++;
            if((num1 & (1<<i)) != 0)
            {
                rightmost = i;
                cnt++;
            }
        }

        cout<<reqcnt<<" "<<cnt<<"r : "<<rightmost<<endl;
        int ans = 0, res;

        if(reqcnt == cnt)
        {
            res = num1;
        }
        else if(reqcnt < cnt)
        {
            int j = rightmost;
            while(j>=0 && reqcnt > 0)
            {
                if((num1 & (1<<j)) != 0) 
                {
                    ans |= (1<<j) ;
                    reqcnt--;
                }
                j--;
            }
            res = ans;
        }
        else
        {
            ans = num1;
            int extra = reqcnt-cnt;
            for(int i=0; i<=31; i++)
            {
                if((num1 & (1<<i)) == 0)
                {
                    ans |= (1<<i);
                    extra--;
                    if(extra == 0) break;
                }
            }
            res = ans;
        }

        return res;
    }
};