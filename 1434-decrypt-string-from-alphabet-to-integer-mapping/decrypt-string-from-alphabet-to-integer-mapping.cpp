class Solution {
public:
    string freqAlphabets(string s) {
        string ans="";
        
        int j=s.size()-1;
        while( j>=0 )
        {
            if(s[j]!='#')
            {
                int temp=s[j--]-'0';
                ans=ans + (char)( (temp-1) + 'a') ;
                
            }

            else
            {
                int temp=stoi(s.substr( j-2, 2));
                ans=ans + (char)( (temp-1) +'a');
                j-=3;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};