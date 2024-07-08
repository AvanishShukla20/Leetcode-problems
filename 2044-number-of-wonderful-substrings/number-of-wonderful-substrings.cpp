class Solution {
public:
    typedef long long ll;

    long long wonderfulSubstrings(string word) {
       unordered_map<ll, ll> mpp;
       mpp[0] = 1;
       ll cumulativexor = 0;
       ll result = 0;

       for(int i=0; i< word.size(); i++)
       {
            // representing each letter as integer like c = 0100 , 1 at 3rd position
            int num = (1 << (word[i] - 'a'));
            cumulativexor ^= num;

            if(mpp.find(cumulativexor) != mpp.end())
            {
                // even substring 
                result += mpp[cumulativexor];
            }

            // check for existence of only 1 character with odd freq
            int temp = cumulativexor;
            for(char ch = 'a'; ch <= 'j'; ch++)
            {
                int num2 = 1 << (ch - 'a');
                if(mpp.find(temp^num2) != mpp.end())
                {
                    result += mpp[temp^num2]; 
                }
            }

            mpp[cumulativexor]++;
       }

       return result;

    }
};