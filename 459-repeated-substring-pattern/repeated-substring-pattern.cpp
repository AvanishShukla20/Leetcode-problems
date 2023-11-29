class Solution {
public:
    bool repeatedSubstringPattern(string s) {
       int sublen;
       string sb="";
       for(int sublen=1; sublen < s.size(); sublen++)
       {
           
           if( s.size() % sublen==0)
           {
               sb=s.substr(0,sublen);
               cout<<sb<<endl;
               string ans="";
               int k=0;
               while(k< s.size()/ sublen )
               {
                   ans+=sb;
                   k++;
                   
               }
               
               if( ans==s ) return true;
           }
       } 
       return false;
    }
};