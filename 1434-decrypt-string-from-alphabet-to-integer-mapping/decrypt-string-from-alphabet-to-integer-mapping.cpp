class Solution {
public:
    string freqAlphabets(string s) {
        string ans="";
        
        int j=s.size()-1;
        while( j>=0 )
        {
            if(s[j]!='#')
            {
                cout<<"s[j] : "<<s[j]<<endl;
                cout<<"s[j]+a : "<<s[j]+'a'<<endl;
                int x='a';
                cout<<x<<endl;

                int temp=s[j--]-'0';

                ans=ans + (char)( (temp-1) + 'a') ;
                cout<<"ans :"<<ans<<endl;
            }

            else
            {
                int temp=stoi(s.substr( j-2, 2));
                ans=ans + (char)( (temp-1) +'a');
                cout<<"ans :"<<ans<<endl;
                j-=3;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};