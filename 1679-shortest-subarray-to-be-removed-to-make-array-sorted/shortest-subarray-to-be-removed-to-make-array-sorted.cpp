class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int j=n-1;
        while(j> 0 && arr[j-1] <= arr[j]) j--;

        int i=0,ans = j;
        while(j<n && i<j)
        {
            if(arr[i] <= arr[j])
            {
                ans = min(ans, j-i-1);
                if(arr[i] > arr[i+1]) break;
                else i++;
            }
            else j++;
        }
        ans = min(ans, j-i-1);
        //if j ended but some sorted part can be more covered by idx i
        while(i< n-2 && arr[i]<=arr[i+1]) 
        {
            i++;
            ans = min(ans, j-i-1);
        }

        return ans <= 0 ? 0 : ans;
    }
};