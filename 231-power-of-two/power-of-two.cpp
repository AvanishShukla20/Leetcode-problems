class Solution {
public:
    bool isPowerOfTwo(int n) {
        //simply count no of set bits 
        if(n<0) return false;
        int count=0;
        for(int i=0; i<32; i++)
        {
            if((n & (1<<i)) != 0) count+=1;

        }
        cout<<"count "<<count<<endl;
        if(count==1) return true;
        else return false;
    }
};