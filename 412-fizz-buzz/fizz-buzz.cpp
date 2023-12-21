class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector< string > ans;
        int t;

       for(int i=0; i<n ; i++)
       {
           t = i+1;

           if( t%15==0)
           {
               ans.push_back("FizzBuzz");

           }
           else
           {
               if(t%3==0) ans.push_back("Fizz");
               else if(t%5==0) ans.push_back("Buzz");
               else ans.push_back(to_string(t));
           }
       } 
       return ans;
    }
};