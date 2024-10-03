class Solution {
public:
    bool solve(int i, int j, string&s, string& p)
    {
        if(j == p.size())
        {
            return (i == s.size());
        }

        //check if current is matching or not
        bool first_match = (i < s.size() && (s[i] == p[j] || p[j] == '.')) ? 1 : 0;

        bool take_asterisk = false;
        if(j+1 < p.size() && p[j+1] == '*')
        {
            if(first_match == true)
            {
                take_asterisk = solve(i+1, j, s, p);
            }
            bool notTake_asterisk = solve(i, j+2, s, p);

            return take_asterisk || notTake_asterisk ;
        }
        else
        {
            return first_match && solve(i+1, j+1, s, p);
        }
    }
    bool isMatch(string s, string p) {
        return solve(0, 0, s, p);
    }
};