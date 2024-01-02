class Solution {
public:
    string greatestLetter(string s) {
      unordered_set<char> key;
      string res = "";
      for(int i=0; i<s.size(); i++)
      {
          key.insert(s[i]);
      }

      for(char ch = 'A'; ch<='Z'; ch++)
      {
          if(key.find(ch) != key.end() and key.find(ch+32) != key.end())
          {
              if(ch > res[0])
              {
                  res = ch;
              }
          }
      } 
      return res; 
    }
};