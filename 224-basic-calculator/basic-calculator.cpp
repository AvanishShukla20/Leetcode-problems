class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int result = 0, currNum = 0;
        int sign = 1;

        for(int i=0; i<s.size(); i++)
        {

            if(s[i] == '(')
            {
                /* push previous result and sign just before this '(' character .So, that once this inner loop is evaluated
                , The evaluated result can be added to final result */ 

                st.push(sign);
                st.push(result);

                //reset all things to evaluate inner things
                currNum = 0;
                sign = 1;
                result = 0;
            }
            else if(s[i] == ')')
            {
                //marks the end of opening brace wala bracket
                result = result + sign * currNum;

                int resBeforeBrace = st.top();
                st.pop();
                int signBeforeBrace = st.top();
                st.pop();

                result = result*signBeforeBrace + resBeforeBrace;
                // reset currNum and sign
                currNum = 0;
                sign = 1;
            }
            else if(isdigit(s[i]))
            {
                // forming number 
                int val = s[i] - '0';
                currNum = 10*currNum + val;
            }
            else if(s[i] == '+' || s[i] == '-')
            {
                //this is breaker points i.e character with '+' or '-' sign 
                result += currNum*sign;

                if(s[i] == '-') sign = -1;
                else sign = 1;
                currNum = 0;
            }
        }
        if(currNum != 0) result += sign*currNum;
        return result;
    }
};