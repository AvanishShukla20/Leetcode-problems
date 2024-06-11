class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mpp;
        int n =  s.size();
        int countOfOddfreqChars = 0;
        for(int i=0; i<n; i++)
        {
            mpp[s[i]]++;
            if(mpp[s[i]]%2 != 0) countOfOddfreqChars++;
            else countOfOddfreqChars--; 
        }

        if(countOfOddfreqChars > 0) return s.size() - countOfOddfreqChars + 1;
        return s.size();
          
    }
};