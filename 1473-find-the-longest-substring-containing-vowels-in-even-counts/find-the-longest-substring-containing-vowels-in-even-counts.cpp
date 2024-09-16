class Solution {
public:
    int findTheLongestSubstring(string s) {
        int hash[5] = {0};
        int n = s.size();
        unordered_map<string, int> mpp;
        mpp["00000"] = -1;
        int res = 0;

        for(int i=0; i<n; i++)
        {
            if(s[i] == 'a')
            {
                hash[0]++;
                hash[0] %= 2;
            }
            if(s[i] == 'e')
            {
                hash[1]++;
                hash[1] %= 2;
            }
            if(s[i] == 'i')
            {
                hash[2]++;
                hash[2] %= 2;
            }
            if(s[i] == 'o')
            {
                hash[3]++;
                hash[3] %= 2;
            }
            if(s[i] == 'u')
            {
                hash[4]++;
                hash[4] %= 2;
            }
            string t = "";
            for(int i=0; i<5;i++) t += to_string(hash[i]);
            
            if(mpp.find(t) != mpp.end()) res = max(res, i - mpp[t]);
            else mpp[t] = i;
        }

        return res;
    }
};