class Solution {
public:
bool solve(string &s,string &p,int i,int j,vector<vector<int>>&dp){
// base condition if  we pass whole p string and check string s is also passed or not 
    if (j == p.length()) {
            return i == s.length();
        }

    
     // if the i,j is  already computed than skip to find
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    // find the character at i index of string s anf the character at j index aat string p is equal or p[j]='.' than firstMatch is true
    bool firstMatch = (i < s.length() && (s[i] == p[j] || p[j] == '.'));
// check for the use of '*' if '*' is use for skip or how many seqence repetedly
//store the value in dp 
  if (j + 1 < p.length() && p[j + 1] == '*') {
           
            dp[i][j] = solve(s, p, i, j + 2, dp) || (firstMatch && solve(s, p, i + 1, j, dp));
        } else {
          
            dp[i][j] = firstMatch && solve(s, p, i + 1, j + 1, dp);
        }
//return dp[i][j]
    return dp[i][j];
}
    bool isMatch(string s, string p) {
       //intialize dp vector with length+1 
        vector<vector<int>>v(s.length()+1,vector<int>(p.length()+1,-1));
//call the function
        return solve(s,p,0,0,v);
            
    }
};