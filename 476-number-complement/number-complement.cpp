class Solution {
public:
    int findComplement(int num) {
        int k = 31;
        for(int i = 31; i>=0; i--)
        {
            if((num & (1<<i)) != 0) break;
            k--;
        }

        int cnt = 0;
        for(int i = 0; i<31; i++)
        {
            if(cnt > k) break;
            num = num ^ (1 << i);
            cnt++;
        }
        return num;
    }
};