class Solution {
public:
    int minimumDeletions(string s) {
        // goal -> string should look like aaaaa....bbbbb....

        /*So at every index we try deleting all problem create karne wale cases i.e where there exists a "b" before it and there exists an "a" after it */

        int b_cnt = 0, n = s.size();
        int a_cnt = 0;

        unordered_map<int, pair<int, int>> mpp;

        for(int i = 0; i < s.size(); i++)
        {
            mpp[i].second = b_cnt;
            if(s[i] == 'b') b_cnt++;
        }

        for(int i = n - 1 ; i>= 0; i--)
        {
            mpp[i].first = a_cnt;
            if(s[i] == 'a') a_cnt++;
        }

        //treat every index as break point

        int min_steps = 1e9;
        for(int i = 0 ; i<n; i++)
        {
            int steps = mpp[i].first + mpp[i].second;
            min_steps = min(min_steps, steps);
        }

        return min_steps;
    }
};