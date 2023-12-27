class Solution {
public:
    // note the mapping
    vector < string > mapping ={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    vector<string> helper (string &digits)
    {
        if(digits.size() == 0)
        {
            vector<string> res = {""};
            return res;
        }

        char ch = digits[0];

        string rest = digits.substr(1);
        // we will subtract '2' this time 
        string mappedletters = mapping[ch-'2'];

        vector<string> curr;

        for(auto x : helper(rest))
        {
            for(int i=0; i< mappedletters.size(); i++)
            {
                curr.push_back(mappedletters[i]+x);
            }
        }
        return curr;
    }

    vector<string> letterCombinations(string digits){

        if(digits.size()==0) 
        {
            return {};
        }
        else
        {
            vector <string> ans = helper(digits);
            return ans;
        }

        
         
    }
};