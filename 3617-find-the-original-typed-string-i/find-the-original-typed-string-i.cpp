class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1;
        int i =0;
        while(i < word.size())
        {
            char ch = word[i];
            int cnt = 0;
            while(i<word.size() && word[i] == ch)
            {
                cnt++;
                i++;
            }
            ans += (cnt-1);
        }
        return ans;
    }
};