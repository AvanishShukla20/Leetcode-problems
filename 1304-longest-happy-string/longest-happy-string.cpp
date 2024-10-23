class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;

        if(a >0) pq.push({a, 'a'});
        if(b>0) pq.push({b, 'b'});
        if(c>0) pq.push({c, 'c'});
        string str = "";
        char flag ='#';
        char prev_ch;
        int prev_freq;
        while(pq.size() > 1)
        {
            auto it1 = pq.top();
            pq.pop();
            auto it2 = pq.top();
            pq.pop();

            int fc1 = it1.first, fc2 = it2.first;
            char ch1 = it1.second, ch2 = it2.second;

            if(fc1 >= 2)
            {
                if(prev_ch != ch1)
                {
                    fc1 -= 2;
                    flag = ch1;
                    str += string(2, ch1);
                    prev_ch = ch1;
                    prev_freq = 2;
                }
            }
            else if(fc1 == 1)
            {
                if(prev_ch == ch1)
                {
                    if(prev_freq < 2)
                    {
                        fc1 -= 1;
                        str += ch1;
                        prev_ch = ch1;
                        prev_freq = 2;
                    }
                }
                else
                {
                    fc1 -= 1;
                    str += ch1;
                    prev_ch = ch1;
                    prev_freq = 1;
                }
                
            }

            if(fc2 >= 1)
            {
                fc2 -= 1;
                str += ch2;
                prev_ch = ch2;
                prev_freq = 1;
            }

            if(fc1 != 0) pq.push({fc1, ch1});
            if(fc2 != 0) pq.push({fc2, ch2});
        }

        if(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            char ch = it.second;
            int freq = it.first;
            if(freq == 1) str += ch;
            else str += string(2, ch);

        }

        return str;
    }
};