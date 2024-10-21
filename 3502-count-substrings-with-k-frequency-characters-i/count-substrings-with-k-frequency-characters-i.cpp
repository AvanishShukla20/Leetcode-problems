class Solution {
public:
    int getcnt(unordered_map<int, int>& mpp, int& k)
    {
        int cnt =0;
        for(auto it : mpp) if(it.second >= k) return true;
        return false;
    } 
    int numberOfSubstrings(string s, int k) {
        unordered_map<int, int> mpp;
        int i =0,j = 0, n = s.size();
        int ans =0;
        while(i < n)
        {
            mpp[s[i]]++;
            int cnt = getcnt(mpp, k);
            while(j <= i && getcnt(mpp, k)) 
            {
                ans += (n - i);
                mpp[s[j]]--;
                j++;
            }
            i++;
        }
        return ans;

    }
};