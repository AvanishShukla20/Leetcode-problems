class Solution {
public:
    string freqAlphabets(string s) {
        int i=0;
        string ans="";
        stack< int > st;

        while(i<s.length())
        {
            if(s[i]=='#')
            {
                int x1=st.top();
                st.pop();
                int x2=st.top();
                st.pop();

                int res= x2*10 + x1;
                //pushing the result again into stack 
                st.push(res);
            }
            else
            {
                st.push( s[i] - '0' );
            }
            i++;
        }

        
        //now generating an ans string with all the answers in reverse order

        while(!st.empty())
        {
            ans= ans + (char)( st.top()+'a' -1 );
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};