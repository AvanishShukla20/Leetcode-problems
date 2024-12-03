class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int ones = 0, zeroes = 0;
        for(int i =0;i<n; i++)
        {
            if(s[i] == '1') ones++;
            else zeroes++;
        }

        if(n%2 == 0 && ones != zeroes) return -1;
        if(n%2 != 0 && abs(ones - zeroes) > 1) return -1;


        string st1 = "", st2 = "";
        for(int i=0; i<n; i++)
        {
            if(i%2 != 0)
            {
                st1 += '1';
                st2 += '0';
            }
            else
            {
                st1 += '0';
                st2 += '1';
            }
        }
        cout<<st1<<endl;
        cout<<st2<<endl;

        int ans1 = 0, ans2 = 0;
        for(int i = 0; i<n; i++)
        {
            if(st1[i] != s[i]) ans1++;
            if(st2[i] != s[i]) ans2++;
        }

        if((ans1 == 0 && ans2 == 0) || (ans1%2 != 0 && ans2%2 != 0)) return -1;
        
        if(ans1%2 == 0 && ans2%2 == 0)
        {
            return min(ans1/2, ans2/2);
        }

        if(ans1%2 != 0)
        {
            if(ans2%2 == 0) return ans2/2;
        }
        return ans1/2;
    }
};