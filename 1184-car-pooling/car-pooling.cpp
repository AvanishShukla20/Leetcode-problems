class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<vector<int>> stopInfo;
         

        /*stopInfo structure = {point,flag, numofPassengers}*/
        for(int i=0; i<trips.size(); i++)
        {
            // 0-> Leaving the bus   1-> Entering the bus
            stopInfo.push_back({trips[i][1], 1, trips[i][0]});
            stopInfo.push_back({trips[i][2], 0, trips[i][0]});    
        }

        
        //to get first element i.e bus Stops  in sorted order
        sort(stopInfo.begin(), stopInfo.end());

        int curr = 0;
        for(int k =0; k< stopInfo.size(); k++)
        {
            if(stopInfo[k][1] == 1) curr += stopInfo[k][2];
            else curr -= stopInfo[k][2];

            if(curr > capacity) return false;
        }
        return true;


    }
};