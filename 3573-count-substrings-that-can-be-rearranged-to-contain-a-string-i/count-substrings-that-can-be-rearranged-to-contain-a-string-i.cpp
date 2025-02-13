class Solution {
public:
    bool isvalid(unordered_map<char, int>& reqmpp, unordered_map<char, int>& currmpp)
    {
        for(auto &it : reqmpp)
        {
            if(currmpp[it.first] < it.second) return false;
        }
        return true;
    }
    long long validSubstringCount(string word1, string word2) {
        unordered_map<char, int> currmpp, reqmpp;
        int n=word1.size(), m= word2.size();

        for(int i=0; i<word2.size(); i++)
        {
            reqmpp[word2[i]]++;
        }

        long long ans = 0, i = 0;
        for(int j=0; j<n; j++)
        {
            char curr = word1[j];
            currmpp[curr]++;

            while(isvalid(reqmpp, currmpp) == true)
            {
                ans += (n-j);
                currmpp[word1[i]]--;
                if(currmpp[word1[i]] == 0) currmpp.erase(word1[i]);
                i++;
            }
        }

        return ans;
    }
};