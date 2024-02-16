class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {

        unordered_map<int, int> mpp;

        for(auto p : arr) mpp[p]++;

        vector<int> freq;
        for(auto x : mpp)
        {
            freq.push_back(x.second);
        }
        
        sort(freq.begin(), freq.end());
        //size of this freq array represents the no of unique elements initially i have

        int noOfElementsThatCanBeRemoved = 0;
        for(int i = 0; i< freq.size(); i++)
        {
            noOfElementsThatCanBeRemoved += freq[i];
            if(noOfElementsThatCanBeRemoved > k) return freq.size() - i ;
        }


        return 0;
    }
};