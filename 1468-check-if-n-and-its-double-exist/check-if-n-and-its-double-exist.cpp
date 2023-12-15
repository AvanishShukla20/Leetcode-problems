class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;
        int countZero=0;
        for(int i=0; i< arr.size(); i++)
        {
            if(arr[i]!=0) s.insert( arr[i]*2 );
            else countZero+=1;
        }

        if(countZero>1) return true;
        else
        {
        for(int i=0; i<arr.size(); i++)
        {
            if(s.find(arr[i]) != s.end()) return true;
        }
        
        return false;
        }

    }
};