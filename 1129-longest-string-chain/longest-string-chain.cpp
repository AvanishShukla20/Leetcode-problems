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
    int longestStrChain(vector<string>& words) {
        
        int n = words.size();
        vector<int> ahead(n+1, 0),curr(n+1, 0);
        sort(words.begin(), words.end(), comp);

        for(int idx = n-1; idx >= 0; idx--)
        {
            for(int prev = idx - 1; prev >= -1; prev--)
            {
                int t1 = 0, t2 = 0, t3 = 0;
                if( prev == -1 || ifPredecessor(words[prev], words[idx]))
                {
                    //take 
                    t1 = ahead[idx + 1] + 1;
            //not_take
                    t2 = ahead[prev + 1];
                }
                    t3 = ahead[prev + 1];
                    curr[prev+1] = max(t1, max(t2, t3));
            }
            ahead = curr;
        }
        

        return curr[0];
    }
};