class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

        // dp[i][j] -> length of sequence ending with arr[j], arr[i] as its last two elements

        unordered_map<int, int> mpp; // value VS Idx for quick lookup
        for(int i=0; i<n; i++){
            mpp[arr[i]] = i;
        }

        int ans = 1;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                int req = abs(arr[i] - arr[j]);
                if(mpp.find(req) != mpp.end() && mpp[req] < j)
                {
                    // the idx of req must be lesser than j
                    dp[i][j] = dp[j][mpp[req]] + 1;
                }
                else
                {
                    // this is THE KEY YOU AND EVERY OTHER PERSON MISSES -> 

                    dp[i][j] = 2; // starting a new sequence with arr[i], arr[j]
                }
                ans = max(ans, dp[i][j]);
            }
        }

        return (ans > 2) ? ans : 0;

    }
};