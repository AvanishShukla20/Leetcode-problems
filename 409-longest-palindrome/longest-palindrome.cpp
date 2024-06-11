class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mpp;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            mpp[s[i]]++;
        }

        int len = 0;
        int isFreqOdd = 0;

        for (auto it : mpp) {
            if (it.second % 2 != 0) {
                len += it.second - 1;
                isFreqOdd = 1;
            } else
                len += it.second;
        }

        if(isFreqOdd) len = len + 1;
        return len;
    }
};