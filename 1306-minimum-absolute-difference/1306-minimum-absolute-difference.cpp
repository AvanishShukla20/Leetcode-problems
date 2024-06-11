class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>> ans;

        int mindiff = INT_MAX;
        for(int i=0; i < n-1; i++)
        {
            if(arr[i+1] - arr[i] < mindiff)
            { 
                // very imp note-> you used clear function of vector for the first time 
                ans.clear();
                mindiff = arr[i+1] - arr[i];
                ans.push_back({arr[i], arr[i+1]});
            }
            else if(arr[i+1] - arr[i] == mindiff)
            {
                ans.push_back({arr[i], arr[i+1]});
            }
        }

        return ans;
    }
};