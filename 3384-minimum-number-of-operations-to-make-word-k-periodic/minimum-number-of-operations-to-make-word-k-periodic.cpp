class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int minfreqofPartition = 0;

        unordered_map<string, int> mpp;
        int n = word.size();
         //no of partitions are  n/k ...take time and realise
        for(int i= 0; i<n; i += k)
        {
            string partition = word.substr(i, k);
            mpp[partition]++;
            minfreqofPartition = max(minfreqofPartition, mpp[partition]);

        }

        // realise this by taking an example ->
        int ans = n/k - minfreqofPartition;
        return ans;
    }
};