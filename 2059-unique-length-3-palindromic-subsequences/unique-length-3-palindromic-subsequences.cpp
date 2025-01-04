class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        // ques was all about focusing on palindrome. NOT ON forming Subsequence which you always c**tiyo type do
        unordered_map<char, pair<int, int>> mpp;

        for(char ch = 'a'; ch <='z'; ch++)
        {
            bool first = false;
            int cnt = 0;
            for(int i=0; i<n; i++)
            {
                if(s[i] == ch)
                {
                    cnt++;
                    if(first == false)
                    {
                        mpp[ch].first = i;
                        first = true;
                    }
                    else mpp[ch].second = i;
                }
            }
            if(cnt == 1)
            {
                mpp.erase(ch);
            }
        }

        unordered_set<char> st;
        int ans = 0;
        for(auto &it : mpp)
        {
            //cout<<it.first<<" -> "<<it.second.first<<" , "<<it.second.second<<" ->.... ";
            int s_idx = it.second.first;
            int e_idx = it.second.second;
            s_idx += 1;
            while(s_idx < e_idx)
            {
                st.insert(s[s_idx]);
                s_idx++;
            }
            //cout<<st.size()<<endl;
            ans += st.size();
            st.clear();
        }

        return ans;

    }
};