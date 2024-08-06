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
            if(i <= 7) ans += hash[i]*1;
            else if(i >= 8 && i <= 15) ans += hash[i]*2;
            else if(i > 15 && i <= 23) ans += hash[i]*3;
            else ans += hash[i]*4;
        }


        return ans;
    }
};