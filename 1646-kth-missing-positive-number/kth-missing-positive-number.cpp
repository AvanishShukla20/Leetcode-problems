class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> s;
        for(int i=0; i< arr.size(); i++)
        {
            s.insert(arr[i]);
        }
        int j = 1;
        while(k > 0)
        {
            if(s.find(j) == s.end())
            {
                k--;
            }
            j++;
        }
        return j-1;
    }
};