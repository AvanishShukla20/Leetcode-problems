class Solution {
public:
    int minimumPushes(string word) {
       int size = word.size();
       int i=1,turn, x = size, res =0;
       while(x != 0)
       {
       if(x < 8) turn = x;
       else turn = 8;
       res += i*turn;
       x -= turn;
       i++;
       }
       return res; 
    }
};