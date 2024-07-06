class Solution {
public:
    int passThePillow(int n, int time) {
        int ans = 0;
        if(n == 1)
        {
            return 1;
        }
        else if(time == n)
        {
            ans =  n - 1;
        }
        else if(time > n)
        {
            int div = time/(n-1);
            int mod = time % (n-1);
            if(div%2 == 0)
            {
                ans = mod + 1;
            }
            else
            {
                ans = n - mod;
            }
             
        }
        else
        {
           ans = time + 1 ;
        }
        return ans;
        
    }
};