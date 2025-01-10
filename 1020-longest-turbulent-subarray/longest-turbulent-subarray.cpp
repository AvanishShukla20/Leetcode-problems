class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return 1;
        vector<int> comp(n-1);
        

        

        int ans = 1; // Maximum length of turbulent subarray
        int i = 0; // Start index of the current window

        for (int j = 1; j < n; j++) {
            int cmp = (arr[j - 1] < arr[j]) ? 1 : (arr[j - 1] > arr[j] ? -1 : 0);

            if (cmp == 0) {
                // Reset the start of the turbulent subarray
                i = j;
            } 
            
            else if (j == n - 1 || cmp * ((arr[j] < arr[j + 1]) ? 1 : (arr[j] > arr[j + 1] ? -1 : 0)) != -1) {
                // If the current sequence breaks or we reach the end, update the answer
                ans = max(ans, j - i + 1);
                i = j;
            }
        }

        return ans;
    }
};