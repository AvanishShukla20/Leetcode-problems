class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
     unordered_map<char,int> CharIdxmpp;

     int i=0,temp,res=-1;
     while( i< s.size())
     {
        if(CharIdxmpp.find(s[i]) != CharIdxmpp.end())
        {
            temp = i - CharIdxmpp[s[i]]-1;
            if(temp > res) res = temp;
            i++;
        }
        else
        {
            CharIdxmpp[s[i]] = i;
            i++;
        }
        
     }

        return res;
    }
};