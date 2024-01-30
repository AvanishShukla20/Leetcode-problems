class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        
        for(int i=0; i<batteryPercentages.size(); i++)
        {
            if(batteryPercentages[i] > 0) 
            {
                batteryPercentages[i] +=1;
                for(int j=i+1; j<batteryPercentages.size(); j++)
                {
                    if(batteryPercentages[j] == 0) continue;
                    else batteryPercentages[j] -= 1;
                }
            }
        }

        int ans = 0;
        for(int i=0; i<batteryPercentages.size(); i++)
        {
            if(batteryPercentages[i] > 0) ans++;
        }

        return ans;

    }
};