class Solution {
public:
    int countHomogenous(string s) {
       //applying two pointers to extarct out sizes of substring sizes with same letters 

       //size vector
        vector<int> subSize;

        int i=0,j=0,n=s.size();

        while(j < n)
        {
            if(s[j] != s[i])
            {
                subSize.push_back(j-i);
                i=j;
            }
                j++;
        }

        // inserting size of last substring

        subSize.push_back(j - i);

        long res=0,m;

        for(int i=0; i< subSize.size(); i++)
        {
            m = subSize[i];
            res += m * (m+1)/2; 
        }
        return res % (int)(pow(10,9)+7 );
    }
};