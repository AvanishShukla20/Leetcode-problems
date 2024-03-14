class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int i = 0, j = 0;
        while(i < s.size() && j < spaces.size())
        {
            if(i == spaces[j])
            {
                ans += " ";
                j++;
            }
            ans += s[i];
            i++;
        }
        while(i<s.size())
        {
            ans += s[i];
            i++;
        }
        return ans;

    }
};