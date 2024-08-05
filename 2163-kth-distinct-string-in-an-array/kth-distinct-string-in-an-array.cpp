class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n = arr.size();
        unordered_map<string, int> mpp;
        for(int i=0; i<n; i++)
        {
            mpp[arr[i]]++;
        }
        int cnt = 0;
        string ans = "";
        
        for(int i =0; i<n; i++)
        {
            if(mpp[arr[i]] == 1)
            {
                cnt++;
                if(cnt == k)
                {
                    ans = arr[i];
                    break;
                }
            }
        }
        return ans;
    }
};