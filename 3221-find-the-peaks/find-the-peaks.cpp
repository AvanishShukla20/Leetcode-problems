class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        int n = mountain.size();
        vector< int> ans ;
        if(n == 1) ans.push_back(0);
        else {
        for(int i=1; i < n -1; i++)
        {
            if(mountain[i] > mountain[i -1] and mountain[i] > mountain[i+1]) ans.push_back(i);
        }
        }
        return ans;
    }
};