class Solution {
public:
    vector<string> commonChars(vector<string>& words) {

        int n = words.size();
        vector<int> count(26, 0);

        for(int i=0; i < words[0].size() ; i++)
        {
            count[words[0][i] - 'a']++;
        }
        

        for(int i =  1; i < n; i++)
        {
            vector<int> tempcount(26, 0);
            for(int j = 0; j < words[i].size(); j++)
            {
                tempcount[words[i][j] - 'a']++;
                
            }

            

            for(int k = 0; k < 26; k++)
            {
                count[k] = min(count[k], tempcount[k]);
            }
        }

        vector<string> ans;

        for(int i = 0; i  < 26 ; i++){
            int freq = count[i];
            while(freq--)
            {
                ans.push_back(string(1, i + 'a'));
            }
            
        }
        
        return ans;
    }
};