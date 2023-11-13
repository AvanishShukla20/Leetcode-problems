class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int i=0;
        char min=letters[0];        
        char res;
        for(;i<letters.size();i++)
        {
            if(letters[i]<min)min=letters[i];
            if((int)letters[i]>(int)target and (int)letters[i]>=(int)min)
            {
                res=letters[i];
                return res;
            }
        }
        return min;
    }
};