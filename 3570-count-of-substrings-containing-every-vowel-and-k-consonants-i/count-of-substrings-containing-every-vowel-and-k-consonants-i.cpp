class Solution {
public:
    bool cntValid(vector<int>& vec, int& k)
    {
        int cons = 0;
        for(int i = 0; i<vec.size(); i++)
        {
            if(i != 0 && i != 4 && i != 8 && i != 14 && i != 20) cons += vec[i];
            else if(vec['a'-'a'] <= 0 || vec['e' - 'a'] <= 0 || vec['i' - 'a'] <= 0 || vec['o' - 'a'] <= 0 || vec['u' - 'a'] <= 0) return false;
        }

        return cons == k;
    }
    int countOfSubstrings(string word, int k) {
        int n = word.size(), ans = 0;
        
        for(int win = k + 5; win <= n; win++)
        {
            int i = 0, j = 0;
            vector<int> vec(26, 0);
            while(j < win)
            {
                vec[word[j] - 'a']++;
                j++;
            }

            if(cntValid(vec, k)) ans++;

            while(j < n)
            {
                vec[word[i] - 'a']--;
                vec[word[j] - 'a']++;
                if(cntValid(vec, k)) ans++;
                i++;
                j++;
            }

        }
        return ans;
    }
};