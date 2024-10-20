class Solution {
public:
    bool parseBoolExpr(string expression) {
        int n = expression.size();
        //ALWAYS FOLLOW THIS METHOD in any evaluation and parentheses problem

        //Take two stacks -> operators and operand(consists '(', 't', 'f')
        stack<char> operators;
        stack<char> operand;

        for(int i =0; i<n; i++)
        {
            if(expression[i] == ')')
            {
                char opr = operators.top();
                operators.pop();
                if(opr == '!')
                {
                    if(operand.top() == 't')
                    {
                        operand.pop();
                        operand.pop();
                        operand.push('f');
                    }
                    else if(operand.top() == 'f')
                    {
                        operand.pop();
                        operand.pop();
                        operand.push('t');
                    }
                }
                else
                {
                    bool ans;
                    if(opr == '&') ans = true;
                    else ans = false;

                    bool opn;
                    while(operand.top() != '(')
                    {
                        if(operand.top() == 't') opn = true;
                        else opn = false;

                        if(opr == '&') ans &= opn;
                        else if(opr == '|') ans |= opn;
                        operand.pop();
                    }
                    operand.pop();
                    (ans == true) ? operand.push('t') : operand.push('f');
                    
                }
            }
            else if(expression[i] == '&' || expression[i] == '|' || expression[i] == '!')
            {
                operators.push(expression[i]);
            }
            else if(expression[i] == 't' || expression[i] == 'f' || expression[i] == '(')
            {
                operand.push(expression[i]);
            }
        }
        if(operand.top() == 'f') return false;
        return true;
    }
};