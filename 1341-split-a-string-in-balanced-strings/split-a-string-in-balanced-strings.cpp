class Solution {
public:
    int balancedStringSplit(string s) {
        int count=0;
        unordered_map<char,int> cmap;
        for(int i=0; i<s.size(); i++)
        {
            cmap[s[i]]++;
            if(cmap['R'] == cmap['L'])
            {
                count++;
            }
        }
        return count;   
    }
};