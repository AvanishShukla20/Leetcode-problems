class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n<=1) return n;
        unordered_map<char, int> hash;
        int i=0,j=0, ans = 1;

        while(j<n)
        {
            hash[s[j]]++;
            while(i<j && hash[s[j]] > 1)
            {
                hash[s[i]]--;
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }

        return ans;
    }
};