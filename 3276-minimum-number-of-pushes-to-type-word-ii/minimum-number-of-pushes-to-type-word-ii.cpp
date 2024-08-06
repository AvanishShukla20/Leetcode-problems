class Solution {
public:
    int minimumPushes(string word) {
        vector<int> hash(26, 0);

        for(int i =0; i<word.size(); i++)
        {
            hash[word[i] - 'a']++;
        }

        sort(hash.rbegin(), hash.rend());
        int ans = 0;
        for(int i = 0; i< 26; i++)
        {
            ans += (i/8 + 1)* hash[i];
        }


        return ans;
    }
};