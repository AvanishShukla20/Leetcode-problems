class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return 1;
        vector<int> comp(n-1);
        

        

        int ans = 1; // Maximum length of turbulent subarray
        int i = 0; // Start index of the current window

        for (int j = 1; j < n; j++) {
            // find the cmp for j and j-1

            int prevcmp = (arr[j - 1] < arr[j]) ? 1 : (arr[j - 1] > arr[j] ? -1 : 0);
            
            int nextcmp = 0;

            if(j<n-1) nextcmp = (arr[j] < arr[j+1]) ? 1 : (arr[j] > arr[j+1] ? -1 : 0);

            if (prevcmp == 0) {
                // Reset the start of the turbulent subarray as the elements are equal to one another
                i = j;
            } 
            else if (j == n - 1 || prevcmp*nextcmp != -1) {
                // If the current sequence breaks or we reach the end, update the answer
                ans = max(ans, j - i + 1);
                i = j;
            }
        }

        return ans;
    }
};