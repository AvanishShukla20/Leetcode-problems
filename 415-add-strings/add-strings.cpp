class Solution {
public:

    
    string addStrings(string num1, string num2) {

       string ans = "";
       int carry = 0, n = num1.size(), m = num2.size();
       int i = n-1, j = m-1;
       while(i >= 0 || j >= 0)
       {
           int sum = 0;
           if(i >= 0)
           {
               sum += num1[i]-'0';
               i--;
           }

           if(j >= 0)
           {
              
               sum += num2[j]-'0';
               j--;
           }

           sum += carry;
           if(sum > 9) carry = 1;
           else carry = 0;
           sum %= 10;
           ans += sum+'0';
       }
       if(carry != 0) ans += '1';
       reverse(ans.begin(), ans.end()); 
       return ans;

    }
};