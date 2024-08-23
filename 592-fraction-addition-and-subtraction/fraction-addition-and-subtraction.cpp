class Solution {
public:
    int gcd(int a, int b)
    {
        if(b == 0) return a;
        return gcd(b, a%b);
    }
    string solve(string s)
    {
        int resNum =  0;
        int resDeno = 1;

        int i=0;
        while(i < s.size())
        {
            int currNum = 0;
            int currDeno = 0;
            bool neg = false;

            if(s[i] == '-' || s[i] == '+')
            {
                if(s[i] == '-') neg = true;
                i++;
            }

            while(isdigit(s[i]))
            {
                int val = s[i] - '0';
                currNum = currNum*10 + val;
                i++;
            }
            if(neg == true) currNum *= -1;

            //skip '/'
            i += 1;

            // form deno
            while(isdigit(s[i]))
            {
                int val2 = s[i] - '0';
                currDeno = currDeno*10 + val2;
                i++;
            }

            resNum = resNum*currDeno + resDeno*currNum;
            resDeno = resDeno*currDeno;

        }
        cout<<resNum<<" "<<resDeno<<endl;

        int div = abs(gcd(resNum, resDeno));
        cout<<"gcd : "<<div<<endl;

        resNum /= div;
        resDeno /= div;

        return to_string(resNum) + '/' + to_string(resDeno);

    }
    string fractionAddition(string expression) {
        return solve(expression);
    }
};