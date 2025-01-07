class Solution {
public:
    vector<int> computeLPS(string& pat) {
        int n= pat.size();
        int i=1, len = 0;
        vector<int> lps(n, 0);
        
        while(i < n)
        {
            if(pat[i] == pat[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if(len == 0)
                {
                    lps[i] = 0;
                    i++;
                }
                else
                {
                    len = lps[len-1];
                }
            }
        }
        return lps;
    }

    bool isPatternInText(string& txt, string& pat) {
        if(pat.empty()) return true;
        if(txt.length() < pat.length()) return false;

        vector<int> lps = computeLPS(pat);
        int i = 0;
        int j = 0;

        while(i < txt.length()){
            if(txt[i] == pat[j]){
                i++;
                j++;
                if(j == pat.length()){
                    return true;
                }
            }
            else{
                if(j != 0){
                    j = lps[j -1];
                }
                else{
                    i++;
                }
            }
        }
        return false;
    }

    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        // I am using sort by size because by default sort function willl sort by lexicographical order which i do not want
        sort(words.begin(), words.end(), [](const string& a, const string& b) -> bool {
            return a.length() < b.length();
        });

        for(int i = 0; i < words.size(); ++i){
            for(int j = i + 1; j < words.size(); ++j){
                if(isPatternInText(words[j], words[i])){
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
};