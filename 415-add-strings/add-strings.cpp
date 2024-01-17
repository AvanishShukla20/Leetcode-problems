class Solution {
public:
  void res(int i1, int i2, string num1, string num2, int carry, string& ans)
    {
        if(i1 < 0 && i2 < 0 && carry == 0)
        {
           return;
        }
        int sum=0;
        if(i1 >= 0) sum += num1[i1]-'0';
        if(i2 >= 0) sum += num2[i2]-'0';
        sum += carry;
        if(sum > 9) carry = 1;
        else carry = 0;
        sum %= 10;
        ans += sum+'0';
        res(i1-1, i2-1, num1, num2, carry, ans); 
    }

    string addStrings(string num1, string num2) {
       string ans = "";
       
       /* Obvious Mistake of a beginner Step ->  res(0,0, num1, num2, 0, ans); */
        //master plan -> we are starting our function calls starting from last indices first

        res(num1.size()-1, num2.size()-1, num1, num2, 0,ans);
        reverse(ans.begin(), ans.end());
        return ans;

    }
};