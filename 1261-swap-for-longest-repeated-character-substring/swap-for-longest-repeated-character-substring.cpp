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
            if(freq[c] > len)
            {
                len += 1;
            }
            ans = max(ans, len);

            // Case 2: Merge two groups separated by one character 
            if (i > 0 && i < groups.size()-1 && groups[i - 1].first == groups[i + 1].first &&
                groups[i].second == 1) {


                int mergedlen = groups[i - 1].second + groups[i + 1].second;
                if(freq[groups[i - 1].first] > mergedlen)
                {
                    mergedlen += 1;
                }
                ans = max(ans, mergedlen); // i have an extra character to swap
            }
        }

        return ans;
    }
};
