class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int count;
        vector<int> DevicesPerRow;
        for(int i=0; i<bank.size(); i++)
        {
            count = 0;
            for(int j=0; j<bank[i].size(); j++)
            {
                if(bank[i][j] == '1') count++;
            }
            DevicesPerRow.push_back(count);
        }

        //using two pointers on DevicesPerRow vector to calculate result
        int res = 0, s = 0,e = 1;
        while(e < DevicesPerRow.size())
        {
            if(DevicesPerRow[e] == 0)
            {
                e++;
            }
            else
            {
                res += DevicesPerRow[s] * DevicesPerRow[e];
                s = e;
                e++;
            }

        }
        return res;

    }
};