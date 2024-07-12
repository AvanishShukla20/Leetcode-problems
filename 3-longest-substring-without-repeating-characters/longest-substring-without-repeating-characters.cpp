class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> mpp;
        int n = s.size(), l = 0, r = 0, ans = 0;

        while(r < n)
        {
            mpp[s[r]]++;
            while(l <= r && mpp[s[r]] >= 2)
            {
                mpp[s[l]]--;
                l++;
            }

            if(mpp[s[r]] < 2)
            {
                ans = max(ans, r - l + 1);
            }
            r++;
        }
        return ans;
    }
};