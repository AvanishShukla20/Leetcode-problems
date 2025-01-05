class Solution {
public:
    // ekdm NAYA !!
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n= s.size();

        vector<int> diff(n, 0);

        for(int i=0; i<shifts.size();i++)
        {
            int left = shifts[i][0];
            int right = shifts[i][1];
            int adder = (shifts[i][2] == 0) ? -1 : 1;

            diff[left] += adder;
            if(right+1 < n)
            {
                diff[right+1] -= adder;
            }
        }


        // now take cumulative sums of diff array to et overall shifts for each idx

        for(int i=1; i<n; i++)
        {
            diff[i] = diff[i]+diff[i-1];
        }


        string ans = "";


        for(int i=0; i<n; i++)
        {
            cout<<diff[i]<<endl;
            char ch = s[i];
            char ch1 = ((ch-'a'+diff[i])%26+26)%26 +'a';

            ans += ch1;
        }

        return ans;
    }
};