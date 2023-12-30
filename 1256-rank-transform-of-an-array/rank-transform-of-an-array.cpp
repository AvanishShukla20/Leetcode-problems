class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
       vector<int> temp(arr.begin(),arr.end());
       sort(temp.begin(),temp.end());
       unordered_map<int,int> mpp;
       int count=1, i=0;
       while(i<temp.size())
       {
           if(mpp.find(temp[i]) == mpp.end())
           {
               mpp[temp[i]] = count;
               count++;
           }
           i++;
       }
       
       for(int i=0; i<arr.size(); i++)
       {
           arr[i] = mpp[arr[i]];
       }
       return arr;
    }
};