class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s ="123456789";
        int DigLow = to_string(low).size();
        int DigHigh = to_string(high).size();
        int n = s.size();
        vector<int> ans;
        for(int i=DigLow; i<= DigHigh; i++)
        {
            for(int j=0; j <= n - i; j++)
            {
                int  temp = stoi(s.substr(j, i));
                if(low <= temp and temp <= high) ans.push_back(temp);
            }
        }
        return ans;
    }
};