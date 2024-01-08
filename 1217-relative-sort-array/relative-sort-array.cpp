class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mpp;
        // Count occurrences of elements in arr1
        for(auto p : arr1)
        {
            mpp[p]++;
        }

        vector<int> ans;

        for(int i=0; i<arr2.size(); i++)
        {
            int m = mpp[arr2[i]];
            while(m--)
            {
                ans.push_back(arr2[i]);
            }
            //this is the thing jo bewakoof tum bhool gaye the to do-> 
            mpp.erase(arr2[i]);
        }

        //add remaining elements to  vector

        for(auto x : mpp)
        {
            int count = x.second;
            while(count--)
            {
                ans.push_back(x.first); 
            } 
        }

        return ans;
    }
};