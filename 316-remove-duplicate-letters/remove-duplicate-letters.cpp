class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<bool> used(26, false);
        vector<int> last_idx(26, -1);

        for(int i=0;i<n;i++) last_idx[s[i] -'a'] = i;

        string result = "";
        for(int i=0; i<n; i++)
        {
            if(result.empty())
            {
                result += s[i];
                used[s[i] - 'a']=true;
            }
            else
            {
                if(result.back() < s[i] && used[s[i] - 'a'] == false)
                {
                    result += s[i];
                    used[s[i]-'a'] = true;
                }
                else
                {
                    while(!result.empty() && result.back() >= s[i] && last_idx[result.back()-'a'] > i && used[s[i] - 'a'] == false)
                    {
                        used[result.back()-'a'] = false;
                        result.pop_back();
                    }
                    if(used[s[i] - 'a'] == false)
                    {
                        result += s[i];
                        used[result.back()-'a'] = true;
                    }
                    
                }
            }
        }

        return result;
    }
};