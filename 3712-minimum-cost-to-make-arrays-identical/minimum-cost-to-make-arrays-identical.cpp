class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        int n = arr.size();

        long long ans1 = 0, ans2 = 0;

        for(int i=0; i<n ;i++)
        {
            ans1 += abs(arr[i] - brr[i]);
        }

        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());

        for(int i=0; i<n ;i++)
        {
            ans2 += abs(arr[i] - brr[i]);
        }

        if(ans1 <= ans2+k) return ans1;

        return ans2 + k;
    }
};