class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //INTUITION ->
        //first we sort the strs vector
        //now we look for the first different character in first and last member of sorted strs , because before that different character all characters will be same in every other element of strs (this is the different character jisse last wala element sort hua h as last element)

        sort(strs.begin(), strs.end());

        string first=strs[0];
        string last=strs[strs.size()-1];
        string ans="";

        for(int i=0; i < first.size() and last.size(); i++ )
        {
            if(first[i] != last[i]) break;
            ans+=first[i];    
        }

        return ans;


    }
};