class Solution {
public:
    int solve(int idx, string&s, unordered_set<string>& st, vector<int>& dp)
    {
        if(idx == s.size()) return 0;
        //treating as extra
        if(dp[idx] != -1) return dp[idx];
        int ans = 1 + solve(idx+1, s, st, dp);

        // not treating as extra
        
        //mistake which you were doing was..... YOU WERE STILL CALLING EVEN IF STRING GENETAED IS NEVER PRESENT IN DICT 

        for(int j = idx; j< s.size(); j++)
        {
            string newsub = s.substr(idx, j - idx + 1);
            if(st.find(newsub) != st.end())
            {
                //call only when found in dictionary 
                ans = min(ans, solve(j+1, s, st, dp));
            }
        }
        return dp[idx] = ans;

    }
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        unordered_set<string> st;
        vector<int> dp(n+1, -1);
        for(int i=0; i<dictionary.size(); i++)
        {
            st.insert(dictionary[i]);
        }
        return solve(0, s, st, dp);
    }
};