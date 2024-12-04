class Solution {
public:
    int countDiff(int i,int j, string& check, string& org)
    {
        int cnt = 0;
        while(i<j)
        {
            if(check[i] != org[i]) cnt++;
            i++;
        }
        return cnt;
    }
    int minFlips(string s) {
        int n = s.size();
        int wind = n;

        string st = s + s;

        string check1 = "", check2 = "";
        int i = 0;
        while(i<2*n)
        {
            if(i%2 == 0)
            {
                check1 += '1';
                check2 += '0';
            }
            else
            {
                check1 += '0';
                check2 += '1';
            }
            i++;
        }
        cout<<"s : "<<st<<" check1 : "<<check1<<" check2 : "<<check2<<endl;

        int diff1 = countDiff(0, n, check1, st);
        int diff2 = countDiff(0, n, check2, st);
        cout<<diff1<<" "<<diff2<<endl;
        int j = 0,k = n;
        int ans = 2*n;

        while(k < 2*n)
        {
            if(st[j] != check1[j])
            {
                diff1 -= 1;
            }
            if(st[j] != check2[j])
            {
                diff2 -= 1;
            }
            if(st[k] != check1[k])
            {
                diff1 += 1;
            }
            if(st[k] != check2[k])
            {
                diff2 += 1;
            }

            ans = min({ans, diff1, diff2});
            k++;
            j++;
        }
        return ans;

    }
};