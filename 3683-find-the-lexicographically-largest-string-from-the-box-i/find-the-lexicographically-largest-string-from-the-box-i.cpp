class Solution {
public:
    string answerString(string word, int numFriends) {
        int n= word.size();
        if(numFriends == 1) return word;
        int len= n - numFriends + 1;

        string maxi = "";
        for(int i=0; i<n; i++)
        {
            maxi = max(maxi, word.substr(i, len));
        }

        return maxi;
    }
};