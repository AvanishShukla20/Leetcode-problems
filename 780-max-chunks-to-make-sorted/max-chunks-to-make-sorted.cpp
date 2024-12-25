class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> maxvec(n), minvec(n);

        maxvec[0] = arr[0];
        for(int i=1;i<n;i++)
        {
            maxvec[i] = max({maxvec[i-1], arr[i-1], arr[i]});
        }

        minvec[n-1] = arr[n-1];
        for(int i =n-2; i>=0; i--)
        {
            minvec[i] = min({minvec[i+1],arr[i], arr[i+1]});
        }
        
        int chunk = 0;
        for(int i=1;i<n;i++)
        {
            if(i == 0 || maxvec[i-1] < minvec[i]) chunk++;
        }
        return chunk+1;
    }
};