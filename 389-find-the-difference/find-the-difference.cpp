class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans ;
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        
        for(char ch1 : s) m1[ch1]++;
        for(char ch2 : t) m2[ch2]++;

        for(auto x2 : m2)
        {
            if( x2.second != m1[x2.first] )
            {
                ans = x2.first;
            }
        }
        return ans;
    }    
};