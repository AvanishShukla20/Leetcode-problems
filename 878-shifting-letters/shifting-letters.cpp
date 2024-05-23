class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        // int n = s.size()
        
        // for(int i = n - 2; i >= 0; i--)
        // {
        //     shifts[i] = (shifts[i] + shifts[i+1]) % 26;
        // }

        // for(int i = 0; i<s.size(); i++)
        // {
        //     s[i] = (s[i] - 'a' + shifts[i]) % 26 + 'a';
        // }

        // return s;
        int sum = 0;
        string ans = "";
        for(int i = 0; i< shifts.size(); i++) sum = (sum + shifts[i]%26) % 26;

        for(int i = 0; i<s.size(); i++)
        {
            ans += (((s[i] - 'a') + sum) % 26+ 'a');
            // this will not work realise imp -> sum = sum - shifts[i]%26;
            sum = (sum - shifts[i]%26 + 26) % 26;
        }

        return ans;
    }
};