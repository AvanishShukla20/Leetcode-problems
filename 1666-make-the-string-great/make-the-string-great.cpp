class Solution {
public:
    string giveGreat(int idx, string s)
    {
        if(idx == s.size())
        {
            return "";
        }
        string rec = giveGreat(idx+1, s);
        
        

        if(!rec.empty() && ( (s[idx]>='a' and s[idx]<='z' and rec[0] == abs(s[idx]-32)) || (s[idx]>='A' and s[idx]<='Z' and rec[0] == s[idx]+32)) )
        {
            rec.erase(0,1); //0 is the index to be deleted
        }
        else
        {
            rec = s[idx] + rec; // this means if s[idx] = J and rec = k  then finally rec = "Jk"
        }
        return rec;   
    }
    string makeGood(string s) {
        return giveGreat(0,s);
    }
};