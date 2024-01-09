class Solution {
public:
    string invertBin(string s)
    {
        //this is new thing to flip a bit -> Do XOR with 1 at every index
        for(int i=0; i<s.size(); i++)
        {
            s[i] =  (s[i]-'0')^1 +'0';
        }
        return s;
    }
    string formInteger(int n)
    {
        if(n == 2)
        {
            return "011";
        }
        string getprev = formInteger(n-1);
        //now invert this getprev
        string rev = invertBin(getprev);
        reverse(rev.begin(), rev.end());

        return getprev + '1' + rev ;
    }
    char findKthBit(int n, int k) {
        if(n == 1) return '0';
        string ans = formInteger(n);
        cout<<ans<<endl;
        return ans[k-1];
    }
};