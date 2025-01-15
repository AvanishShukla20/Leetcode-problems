class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.size();
        stack<int> openBraces; // store indices of open braces with locked = '1'
        stack<int> flexibleBraces;

        for(int i=0; i<n; i++)
        {
            char ch = s[i];
            char num = locked[i];

            if(num == '0')
            {
                flexibleBraces.push(i);
            }
            else
            {
                if(ch == '(')
                {
                    openBraces.push(i);
                }
                else
                {
                    if(openBraces.empty() && flexibleBraces.empty())
                    {
                        // there is no one to balance
                        return false;
                    }
                    if(!openBraces.empty()) openBraces.pop();
                    else if(!flexibleBraces.empty()) flexibleBraces.pop();
                }
            }
        }

        while(!openBraces.empty() && !flexibleBraces.empty())
        {
            if(openBraces.top() >= flexibleBraces.top()) return false;
            openBraces.pop();
            flexibleBraces.pop();
        }

        
        if(openBraces.empty())
        {
            if(flexibleBraces.size()%2 == 0) return true;
            return false;
        }
        
        return false;
    }
};