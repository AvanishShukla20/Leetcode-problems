class Solution {
public:
    bool solve(int i, int j,int& cnt,string&str1, string&str2)
    {
        if(j == str2.size()) return true;
        if(i == str1.size())
        {
            if(j >= str2.size()) return true;
            return false;
        }

        bool ans = false;
        if(cnt == 1)
        {
            if(str1[i] -'a' == str2[j] -'a' || (str1[i]+1 -'a')%26 == (str2[j] -'a'))
            {
                ans = true && solve(i+1, j+1, cnt, str1, str2);
            }  
            else
            {
                ans = false || solve(i+1, j, cnt, str1, str2);
            } 
        }
        else
        {
            if(str1[i] -'a' == str2[j] -'a')
            {
                ans = true && solve(i+1, j+1, cnt, str1, str2);
            }
            else if((str1[i]+1 -'a')%26 == (str2[j] -'a')) 
            {
                cnt += 1;
                ans = true && solve(i+1, j+1, cnt, str1, str2);
                cnt -= 1;
            }
            else
            {
                ans = false || solve(i+1, j, cnt, str1, str2);
            }
        }
        return ans;
    }
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        if(n < m) return false;
        int i=0,j=0, cnt = 0;
        return solve(i, j,cnt, str1, str2);
    }
};