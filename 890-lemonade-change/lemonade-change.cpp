class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveCount=0, tenCount=0, twentyCount=0, i=0;
        while(i<bills.size())
        {
            if(bills[i]==5) fiveCount++;
            else if(bills[i]==10)
            {
                if(fiveCount==0) return false;
                fiveCount--;
                tenCount++;
            }
            else
            {
                if(fiveCount > 0 and tenCount > 0 )
                {
                    fiveCount--;
                    tenCount--;
                }
                //case when 10 ka count==0 but count of 5 is >=3
                else if(fiveCount >= 3) fiveCount-=3;
                else return false;
                twentyCount++;
            }
            i++;
        }
        return true;
    }
};