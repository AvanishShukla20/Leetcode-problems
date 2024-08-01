class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for(int i = 0; i<details.size(); i++)
        {
            string str = details[i].substr(11, 2);
            int age = stoi(str);
            if(age > 60) cnt++;
        }
        return cnt;
    }
};