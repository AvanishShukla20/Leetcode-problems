class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mpp;
         
        vector<int> ans;
        for(auto x : arr1) mpp[x]++;

        int n = arr1.size(), m = arr2.size();

        for(int i = 0; i  < m; i++)
        {
            int count = mpp[arr2[i]];

            while(count != 0)
            {
                ans.push_back(arr2[i]);
                mpp[arr2[i]]--;
                count--;
            }
        }

         
        for(auto it : mpp)
        {
            if(it.second != 0)
            {
                int count = it.second;
                while(count != 0)
                {
                    ans.push_back(it.first);
                    count--;
                }
            }
        }

        
        
        return ans;
    }
};