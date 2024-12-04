class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.size(), m= str2.size();
        int i =0, j = 0;
        while(j < m && i < n)
        {
            if( str1[i]-'a' == str2[j]-'a' || (str1[i] + 1-'a')%26 == (str2[j]-'a')%26)
            {
                i++;
                j++;
            }
            else 
            {
                i++;
            }
        }

        if(j == m) return true;
        return false;
    }
};