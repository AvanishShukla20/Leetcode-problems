class Solution {
public:
    void solve(int idx,string&s, string& currSentence, unordered_set<string>& st, vector<string>& ans)
    {
        if(idx >= s.size())
        {
            ans.push_back(currSentence);
            return;
        }

        for(int j=idx; j<s.size();j++)
        {
            string substri = s.substr(idx, j-idx+1);
            if(st.find(substri) != st.end())
            {
                string tempSentence = currSentence;
                if(!currSentence.empty())
                {
                    currSentence += " ";
                }
                currSentence += substri; // do
                
                solve(j+1, s, currSentence, st, ans); // call function

                currSentence = tempSentence; // undo
            }

        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n= wordDict.size();
        vector<string> res;
        unordered_set<string> mpp;
        for(auto &it :  wordDict)
        {
            mpp.insert(it);
        }
        string currSentence = "";
        solve(0,s,currSentence, mpp, res);
        return res;
    }
};