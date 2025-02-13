class Solution {
public:
    bool isValid(unordered_map<char, int>& reqmpp, unordered_map<char, int>& currmpp) {
        for (auto& it : reqmpp) {
            if (currmpp[it.first] < it.second) 
                return false;
        }
        return true;
    }

    long long validSubstringCount(string word1, string word2) {
        unordered_map<char, int> currmpp, reqmpp;
        int n = word1.size();
        long long ans = 0;
        
        // Populate frequency map for word2
        for (char ch : word2) {
            reqmpp[ch]++;
        }

        int i = 0;  // Left pointer for sliding window

        for (int j = 0; j < n; j++) {
            currmpp[word1[j]]++;  // Expand the window

            // Shrink the window from the left while it's valid
            while (isValid(reqmpp, currmpp)) {
                ans += (n - j);  // Count all substrings starting at i
                currmpp[word1[i]]--;  // Remove leftmost character
                if (currmpp[word1[i]] == 0) currmpp.erase(word1[i]);  // Cleanup
                i++;  // Move left pointer
            }
        }

        return ans;
    }
};
