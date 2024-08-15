class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fivecoins =0, tencoins = 0, twentycoins = 0;
        for(int i = 0; i<bills.size(); i++)
        {
            if(bills[i] == 5) fivecoins++;
            else if(bills[i] == 10 && fivecoins > 0)
            {
                tencoins++;
                fivecoins--;
            }
            else if(bills[i] == 20)
            {
                if(tencoins == 0)
                {
                    if(fivecoins >= 3)
                    {
                        fivecoins -= 3;
                        twentycoins++;
                    }
                    else return false;
                }
                else if(fivecoins > 0)
                {
                    fivecoins--;
                    tencoins--;
                    twentycoins++;
                }
                else return false;
            }
            else return false;
        }
        return true;
    }
};