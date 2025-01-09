class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.size();
        unordered_map<char, int> freq;
        vector<pair<char, int>> groups;

        // Count frequency of each character and create groups of consecutive characters
        for (int i = 0; i < n; ) {
            char c = text[i];
            int count = 0;
            while (i < n && text[i] == c) {
                count++;
                i++;
            }
            freq[c] += count;
            groups.emplace_back(c, count);
        }

        int ans = 0;

        for (int i = 0; i < groups.size(); i++) {
            char c = groups[i].first;
            int len = groups[i].second;

            // Case 1: Use all characters in the current group
            ans = max(ans, len + (freq[c] > len ? 1 : 0));

            // Case 2: Merge two groups separated by one character (if possible)
            if (i > 0 && i + 1 < groups.size() && groups[i - 1].first == groups[i + 1].first &&
                groups[i].second == 1) {
                int mergedLen = groups[i - 1].second + groups[i + 1].second;
                ans = max(ans, mergedLen + (freq[groups[i - 1].first] > mergedLen ? 1 : 0));
            }
        }

        return ans;
    }
};
