class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        if(n == 1 && tokens[0] >= power) return 0;
        else if(n == 1 && tokens[0] < power) return 1;

        int i=0, j= n-1, score = 0;

        while(i <= j)
        {
            if(score == 0){ 
                if(tokens[i] <= power){
                    power -= tokens[i];
                    score += 1;
                    i++;
                }
                else break;
            }
            else{
                if(i == j)
                {
                    if(tokens[i] <= power) score += 1;
                    break;
                }
                else if(power < tokens[i])
                {
                    score -= 1;
                    power += tokens[j];
                    j--;
                } 
                else
                {
                    score += 1;
                    power -= tokens[i];
                    i++;
                }  
            }
        }
        return score;
    }
};