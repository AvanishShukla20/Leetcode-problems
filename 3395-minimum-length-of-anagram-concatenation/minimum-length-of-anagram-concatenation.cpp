class Solution {
public:

    bool isvalid(string& s, int len)
    {
        int n = s.size();
        int firstOne[26] = {0}; // make a vector of 26 length and initialise all values as 0 in it
        for(int i=0; i < len ; i++) firstOne[s[i] - 'a']++;
        for(int i = len; i < n; i += len)
        { 
            int remainingOnes[26] = {0};
            for(int k=i; k< i+len; k++) remainingOnes[s[k] - 'a']++;
            for(int k = 0; k < 26; k++)
            {
                if(firstOne[k] != remainingOnes[k]) return false;
            }
        }
        return true;

    }
    int minAnagramLength(string s) {
        int  n = s.size();

        for(int len = 1; len < n; len++)
        {
            if( n % len == 0 && isvalid(s, len))
            {
                return len;
            }
        }
        return n;
    }
};