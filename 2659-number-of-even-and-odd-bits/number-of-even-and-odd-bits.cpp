class Solution {
public:
    vector<int> evenOddBit(int n) {
        int evenCount=0,oddCount=0;
       for(int i=0; i<32; i++)
       {
           if( n & (1<<i))
           {
               if(i%2==0) evenCount++;
               else oddCount++;
           }
       } 
       vector<int> ans={evenCount,oddCount};
       return ans; 
    }
};