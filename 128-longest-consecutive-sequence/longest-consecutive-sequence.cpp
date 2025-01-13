class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return 1;
        }

        // Sort the array
        sort(nums.begin(), nums.end());

        int count = 1;
        int maxLength = 0;
        unordered_set<int> set(nums.begin(), nums.end());

        for (size_t i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) continue; // Skip duplicates
            if (set.count(nums[i] + 1)) {
                count++;
            } else {
                count = 1;
            }
            maxLength = max(maxLength, count);
        }

        maxLength = max(maxLength, count);
        return maxLength;
    }
};