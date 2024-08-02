class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        vector<int> vec(26, 0);

        for(int i = 0; i < n ; i++)
        {
            vec[s[i] - 'a']++;
        }

        unordered_set<int> st;
        int ans = 0;
        for(int i = 0; i < vec.size(); i++)
        {
            int freq = vec[i];
            if(st.find(freq) != st.end())
            { 
                while(freq > 0 && st.find(freq) != st.end())
                {
                    freq -= 1;
                    ans += 1;
                }  
            }

            st.insert(freq);
        }

        return ans;
    }
};