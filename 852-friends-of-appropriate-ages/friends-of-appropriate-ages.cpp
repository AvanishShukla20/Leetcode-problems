class Solution {
public: 

    bool isAccepted(int x, int y)
    {
        return !(y > x || y <= 0.5 * x + 7 || y > 100 && x < 100);
    }
    int numFriendRequests(vector<int>& ages) {
        int res=0 ;
        int x; // this x has only use in calculation purpose

        unordered_map< int, int > mpp;

        for(int x : ages)
        {
            mpp[x]++;
        }
        for(auto p : mpp)
        {
            
            for(auto s  : mpp)
            {
                if(isAccepted(p.first,s.first))
                {
                  //a clever manipulation will take place here So be attentive  
                  if(s.first == p.first) x=1;
                  else x=0;
                  
                  res = res + p.second * ( s.second - x );
                }
            }
        }
        return res;
    }
};