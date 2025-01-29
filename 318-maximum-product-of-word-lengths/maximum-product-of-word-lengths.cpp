class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        
        vector<int> bitmasks(n, 0);
        
        // Precompute bitmasks for each word
        for (int i = 0; i < n; ++i) {
            for (char c : words[i]) {
                bitmasks[i] |= (1 << (c - 'a'));
            }
        }
        
        // Compare each pair of words
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // If bitmasks have no common set bits, compute product
                if ((bitmasks[i] & bitmasks[j]) == 0) {
                    ans = max(ans, int(words[i].size() * words[j].size()));
                }
            }
        }
        
        return ans;
    }
};
