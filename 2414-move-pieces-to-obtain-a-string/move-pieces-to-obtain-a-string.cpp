class Solution {
public:
    #define P pair<char,int>
    bool canChange(string start, string target) {
        queue<P> s1, s2;
        for(int i=0;i<start.size(); i++)
        {
            if(start[i] != '_') s1.push({start[i], i});
        }

        for(int i=0;i<target.size(); i++)
        {
            if(target[i] != '_') s2.push({target[i], i});
        }

        if(s1.size() != s2.size()) return false;
        while(!s1.empty() && !s2.empty())
        {
            auto it1 = s1.front();
            auto it2 = s2.front();

            if(it1.first != it2.first) return false;
            else
            {
                if(it1.first == 'L')
                {
                    if(it1.second < it2.second) return false;
                    s1.pop();
                    s2.pop();
                }
                else
                {
                    if(it1.second > it2.second) return false;
                    s1.pop();
                    s2.pop();
                }
            }
        }

        return true;
    }
};