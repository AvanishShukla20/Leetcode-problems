class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> idxStorage(3, -1);
        int res = 0;
        for(int i = 0; i < s.size(); i++)
        {
            idxStorage[s[i] - 'a'] = i;
            int minEl = min(idxStorage[0], min(idxStorage[1],idxStorage[2]));

            if(minEl != -1)
            {
                res += minEl + 1;
            }
        }

        return res;
    }
};