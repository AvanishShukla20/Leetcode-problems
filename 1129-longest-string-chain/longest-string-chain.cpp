class Solution {
public:
    bool ifPredecessor(string& a, string& b)
    {
        if(a.size() >= b.size() || b.size() - a.size() > 1) return false;

        int i = 0, j = 0;
        /* remember -> a is chhota wala string*/
        while(i < a.size() && j < b.size())
        {
            if(a[i] == b[j]) i++;
            j++;
        }
        if(i == a.size()) return true;
        return false;
    }

    static bool comp(string& a, string& b)
    {
        return a.size() < b.size();
    }

    int solve(int idx, int prev, vector<string>& words, vector<vector<int>>& dp)
    {
        int n = words.size();
        if(idx == n) return 0;
        if(dp[idx][prev+1] != -1) return dp[idx][prev+1];

        int t1 = 0, t2 = 0, t3 = 0;
        if( prev == -1 || ifPredecessor(words[prev], words[idx]))
        {
            //take 
            t1 = solve(idx+1, idx, words, dp) + 1;
            //not_take
            t2 = solve(idx+1, prev, words, dp);
        }

        t3 = solve(idx+1, prev, words, dp);
        return dp[idx][prev + 1] = max(t1, max(t2, t3));
    }
    int longestStrChain(vector<string>& words) {
        
        int n = words.size();
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        sort(words.begin(), words.end(), comp);

        return solve(0, -1, words, dp);
    }
};