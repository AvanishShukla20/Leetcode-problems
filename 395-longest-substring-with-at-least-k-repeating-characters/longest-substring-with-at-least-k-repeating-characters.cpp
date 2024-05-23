class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        if(n == 0 || k > n) return 0;
        if(k <= 1) return n;

        unordered_map<char, int> mpp;
        for(auto ch : s) mpp[ch]++;

        int idx = 0;
        while(idx < n && mpp[s[idx]] >= k) idx++;
        if(idx >= n-1) return idx;

        int anspartition1 = longestSubstring(s.substr(0, idx), k);

        while(idx < n && mpp[s[idx]] < k) idx++;

        int anspartition2;
        if(idx >= n) anspartition2 = 0;
        else anspartition2 = longestSubstring(s.substr(idx), k);

        return max(anspartition1, anspartition2);
    }
};